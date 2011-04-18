#include <Halak/PCH.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/Assert.h>
#include <Halak/CheckedRelease.h>
#include <Halak/Font.h>
#include <Halak/FontString.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Math.h>
#include <Halak/NumericLimits.h>
#include <Halak/Sprite.h>
#include <Halak/Texture2D.h>
#include <Halak/Internal/Glyph.h>
#include <Halak/Internal/TypingContext.h>

namespace Halak
{
    const unsigned short SpriteRenderer::TrianglesPerQuad = 2;
    const unsigned short SpriteRenderer::VerticesPerQuad  = 4;
    const unsigned short SpriteRenderer::IndicesPerQuad   = 6;

    SpriteRenderer::SpriteRenderer(GraphicsDevice* graphicsDevice)
        : graphicsDevice(graphicsDevice),
          vb(nullptr),
          ib(nullptr),
          lockedVertices(nullptr),
          cachedNumberOfQuads(0)
    {
        CreateVertexAndIndexBuffer(100);
    }

    SpriteRenderer::~SpriteRenderer()
    {
        HKAssert(lockedVertices == nullptr); // VB에 Lock이 걸려있습니다.

        CheckedRelease(ib);
        CheckedRelease(vb);
    }

    void SpriteRenderer::Push(const Matrix4& transform)
    {
        Flush(true);

        if (worldTransforms.empty())
            worldTransforms.push(transform);
        else
            worldTransforms.push(worldTransforms.top() * transform);

        const D3DXMATRIX m(static_cast<const float*>(worldTransforms.top()));
        graphicsDevice->GetD3DDevice()->SetTransform(D3DTS_WORLD, &m);
    }

    void SpriteRenderer::Pop()
    {
        Flush(true);

        worldTransforms.pop();
        HKAssert(worldTransforms.empty() == false); // Begin에서 최초로 Push를 하기 때문에 정상적인 Routine이라면 Stack이 비워질 수 없습니다.

        const D3DXMATRIX m(static_cast<const float*>(worldTransforms.top()));
        graphicsDevice->GetD3DDevice()->SetTransform(D3DTS_WORLD, &m);
    }

    const Matrix4& SpriteRenderer::GetTransform() const
    {
        return worldTransforms.top();
    }

    void SpriteRenderer::Begin()
    {
        Begin(Math::PiOver4);
    }

    void SpriteRenderer::Begin(float fieldOfView)
    {
        BeginActually();

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();

        const D3DXVECTOR2 viewportSize = D3DXVECTOR2(static_cast<float>(graphicsDevice->GetViewport().Width), static_cast<float>(graphicsDevice->GetViewport().Height));
        const D3DXVECTOR2 halfViewportSize = D3DXVECTOR2(viewportSize.x * 0.5f, viewportSize.y * 0.5f);
        const float aspect = viewportSize.x / viewportSize.y;

        D3DXMATRIX projection;
        D3DXMatrixPerspectiveFovLH(&projection, fieldOfView, aspect, 0.1f, 10000.0f);
        d3dDevice->SetTransform(D3DTS_PROJECTION, &projection);

        const float distance = Math::Tan(Math::PiOver2 - (fieldOfView * 0.5f)) * halfViewportSize.x / aspect;
        const D3DXVECTOR3 eye = D3DXVECTOR3(halfViewportSize.x, halfViewportSize.y, -distance);
        const D3DXVECTOR3 at = D3DXVECTOR3(halfViewportSize.x, halfViewportSize.y, 0.0f);
        const D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
        D3DXMATRIX view;
        D3DXMatrixLookAtLH(&view, &eye, &at, &up);
        D3DXMATRIX t;
        D3DXMATRIX r;
        D3DXMatrixTranslation(&t, 0.0f, -viewportSize.y, 0.0f);
        D3DXMatrixRotationX(&r, Math::Pi);
        D3DXMATRIX viewResult;
        D3DXMatrixMultiply(&view, &r, &view);
        D3DXMatrixMultiply(&view, &t, &view);
        d3dDevice->SetTransform(D3DTS_VIEW, &view);

        cameraPosition = Vector3(eye.x, eye.y, eye.z);
    }

    void SpriteRenderer::BeginActually()
    {
        struct SetParameter
        {
            SpriteRenderer* renderer;
            IDirect3DDevice9* d3dDevice;

            SetParameter(SpriteRenderer* renderer, IDirect3DDevice9* d3dDevice)
                : renderer(renderer),
                  d3dDevice(d3dDevice)
            {
            }

            void RenderState(D3DRENDERSTATETYPE type, DWORD value, bool revertable)
            {
                DWORD oldValue = 0;
                d3dDevice->GetRenderState(type, &oldValue);

                if (oldValue != value)
                {
                    d3dDevice->SetRenderState(type, value);
                    if (revertable)
                        renderer->oldRenderStates.push_back(OldRenderState(type, oldValue));
                }
            }
            void TextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value, bool revertable)
            {
                DWORD oldValue = 0;
                d3dDevice->GetTextureStageState(stage, type, &oldValue);

                if (oldValue != value)
                {
                    d3dDevice->SetTextureStageState(stage, type, value);
                    if (revertable)
                        renderer->oldTextureStageStates.push_back(OldTextureStageState(stage, type, oldValue));
                }
            }
            void SetSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value, bool revertable)
            {
                DWORD oldValue = 0;
                d3dDevice->GetSamplerState(sampler, type, &oldValue);

                if (oldValue != value)
                {
                    d3dDevice->SetSamplerState(sampler, type, value);
                    if (revertable)
                        renderer->oldSamplerStates.push_back(OldSamplerState(sampler, type, oldValue));
                }
            }
        };

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();

        SetParameter set(this, d3dDevice);
        set.RenderState(D3DRS_ALPHABLENDENABLE, TRUE, false);
        set.RenderState(D3DRS_ALPHAFUNC, TRUE, false);
        set.RenderState(D3DRS_ALPHAREF, 0x00, false);
        set.RenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD, false);
        set.RenderState(D3DRS_CLIPPING, TRUE, false);
        set.RenderState(D3DRS_CULLMODE, D3DCULL_NONE, true);
        set.RenderState(D3DRS_CLIPPLANEENABLE, FALSE, false);
        set.RenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA | D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_GREEN | D3DCOLORWRITEENABLE_RED, false);
        set.RenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA, false);
        set.RenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1, true);
        set.RenderState(D3DRS_ENABLEADAPTIVETESSELLATION, FALSE, true);
        set.RenderState(D3DRS_FILLMODE, D3DFILL_SOLID, false);
        set.RenderState(D3DRS_FOGENABLE, FALSE, true);
        set.RenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, FALSE, true);
        set.RenderState(D3DRS_LIGHTING, FALSE, true);
        set.RenderState(D3DRS_RANGEFOGENABLE, FALSE, true);
        set.RenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE, true);
        set.RenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD, false);
        set.RenderState(D3DRS_SPECULARENABLE, FALSE, true);
        set.RenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA, false);
        set.RenderState(D3DRS_SRGBWRITEENABLE, FALSE, false);
        set.RenderState(D3DRS_STENCILENABLE, FALSE, true);
        set.RenderState(D3DRS_VERTEXBLEND, FALSE, true);
        set.RenderState(D3DRS_WRAP0, 0, false);
        set.RenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE, true);

        set.TextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE, false);
        set.TextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE, false);
        set.TextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE, false);
        set.TextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE, false);
        set.TextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE, false);
        set.TextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE, false);
        set.TextureStageState(0, D3DTSS_TEXCOORDINDEX, 0, false);
        set.TextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE, false);
        set.TextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE, false);
        set.TextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE, false);

        set.SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP, false);
        set.SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP, false);
        set.SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR, false);
        set.SetSamplerState(0, D3DSAMP_MAXMIPLEVEL, 0, false);
        set.SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR, false);
        set.SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR, false);
        set.SetSamplerState(0, D3DSAMP_MIPMAPLODBIAS, 0, false);
        set.SetSamplerState(0, D3DSAMP_SRGBTEXTURE, 0, false);

        d3dDevice->SetFVF(Vertex::FVF);
        d3dDevice->SetStreamSource(0, vb, 0, sizeof(Vertex));
        d3dDevice->SetIndices(ib);

        worldTransforms = std::stack<Matrix4>();
        Push(Matrix4::Identity);

        cachedTexture.Reset();
        cachedNumberOfQuads = 0;

        HKAssert(lockedVertices); // Push에서 Flush할 때 Lock을 겁니다.
    }

    void SpriteRenderer::End()
    {
        Flush(false);

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();

        for (std::deque<OldSamplerState>::const_reverse_iterator it = oldSamplerStates.rbegin(); it != oldSamplerStates.rend(); it++)
            d3dDevice->SetSamplerState((*it).Sampler, (*it).Type, (*it).Value);                
            
        for (std::deque<OldTextureStageState>::const_reverse_iterator it = oldTextureStageStates.rbegin(); it != oldTextureStageStates.rend(); it++)
            d3dDevice->SetTextureStageState((*it).Stage, (*it).Type, (*it).Value);

        for (std::deque<OldRenderState>::const_reverse_iterator it = oldRenderStates.rbegin(); it != oldRenderStates.rend(); it++)
            d3dDevice->SetRenderState((*it).State, (*it).Value);

        oldSamplerStates.clear();
        oldTextureStageStates.clear();
        oldRenderStates.clear();
    }

    void SpriteRenderer::Flush(bool relock)
    {
        if (lockedVertices)
        {
            lockedVertices = nullptr;
            vb->Unlock();
        }

        if (cachedNumberOfQuads > 0)
        {
            IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();
            d3dDevice->SetTexture(0, cachedTexture->GetD3DTexture());
            d3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, cachedNumberOfQuads * VerticesPerQuad, 0, cachedNumberOfQuads * TrianglesPerQuad);
            cachedTexture.Reset();
            cachedNumberOfQuads = 0;
        }

        if (relock)
            vb->Lock(0, quadCapacity * sizeof(Vertex) * VerticesPerQuad, reinterpret_cast<void**>(&lockedVertices), D3DLOCK_DISCARD);
    }

    void SpriteRenderer::Draw(Vector3 position, Vector3 rotation, Vector2 scale, Texture2DPtr texture, const Rectangle& clippingRectangle, Color tint)
    {
        Draw(position, rotation, scale, texture, clippingRectangle, Vector2::Zero, tint);
    }

    void SpriteRenderer::Draw(Vector3 position, Vector3 rotation, Vector2 scale, Texture2DPtr texture, const Rectangle& clippingRectangle, Vector2 origin, Color tint)
    {
        if (cachedTexture != texture || cachedNumberOfQuads >= quadCapacity)
        {
            Flush(true);
            cachedTexture = texture;
            cachedNumberOfQuads = 0;
        }

        const D3DCOLOR d3dColor = tint.ToARGB();
        const float tw = static_cast<float>(texture->GetSurfaceWidth());
        const float th = static_cast<float>(texture->GetSurfaceHeight());
        const float u1 = static_cast<float>(clippingRectangle.GetLeft())   / tw;
        const float v1 = static_cast<float>(clippingRectangle.GetTop())    / th;
        const float u2 = static_cast<float>(clippingRectangle.GetRight())  / tw;
        const float v2 = static_cast<float>(clippingRectangle.GetBottom()) / th;
        const float w  = static_cast<float>(clippingRectangle.Width);
        const float h  = static_cast<float>(clippingRectangle.Height);
        const int index = cachedNumberOfQuads * VerticesPerQuad;

        const D3DXVECTOR3 d3dScale = D3DXVECTOR3(scale.X, scale.Y, 1.0f);
        const D3DXVECTOR3 d3dTranslation = D3DXVECTOR3(position.X - 0.5f, position.Y - 0.5f, position.Z - 0.5f);
        D3DXQUATERNION d3dRotation;
        D3DXQuaternionRotationYawPitchRoll(&d3dRotation, rotation.Y, rotation.X, rotation.Z);

        D3DXMATRIX localTransform;
        D3DXMatrixTransformation(&localTransform, nullptr, nullptr, &d3dScale, nullptr, &d3dRotation, &d3dTranslation);
        D3DXVECTOR3 v[4] = 
        {
            D3DXVECTOR3(0.0f - origin.X, 0.0f - origin.Y, 0.0f),
            D3DXVECTOR3(w    - origin.X, 0.0f - origin.Y, 0.0f),
            D3DXVECTOR3(0.0f - origin.X, h    - origin.Y, 0.0f),
            D3DXVECTOR3(w    - origin.X, h    - origin.Y, 0.0f),
        };
        D3DXVECTOR4 transformed[sizeof(v) / sizeof(v[0])];
        D3DXVec3TransformArray(&transformed[0], sizeof(D3DXVECTOR4), &v[0], sizeof(D3DXVECTOR3), &localTransform, sizeof(v) / sizeof(v[0]));

        lockedVertices[index + 0] = Vertex(transformed[0], d3dColor, D3DXVECTOR2(u1, v1));
        lockedVertices[index + 1] = Vertex(transformed[1], d3dColor, D3DXVECTOR2(u2, v1));
        lockedVertices[index + 2] = Vertex(transformed[2], d3dColor, D3DXVECTOR2(u1, v2));
        lockedVertices[index + 3] = Vertex(transformed[3], d3dColor, D3DXVECTOR2(u2, v2));

        cachedNumberOfQuads++;
    }

    void SpriteRenderer::Draw(Vector3 position, Vector3 rotation, Vector2 scale, const Sprite& sprite, Color tint)
    {
        Draw(position, rotation, scale, sprite.GetTexture(), sprite.GetClippingRectangle(), sprite.GetOrigin(), tint);
    }

    void SpriteRenderer::Draw(Vector3 position, Vector3 rotation, Vector2 scale, const Sprite& sprite, Color tint, Texture2DPtr opacityMap)
    {
        Flush(true);

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
        d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);

        d3dDevice->SetTextureStageState(1, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG2);
        d3dDevice->SetTexture(1, opacityMap->GetD3DTexture());
        d3dDevice->SetFVF(Vertex::DoubleTexturedFVF);

        // Draw
        {
            const D3DCOLOR d3dColor = tint.ToARGB();
            const float tw1 = static_cast<float>(sprite.GetTexture()->GetSurfaceWidth());
            const float th1 = static_cast<float>(sprite.GetTexture()->GetSurfaceHeight());
            const float tw2 = static_cast<float>(opacityMap->GetSurfaceWidth());
            const float th2 = static_cast<float>(opacityMap->GetSurfaceHeight());
            const float u11 = static_cast<float>(sprite.GetClippingRectangle().GetLeft())   / tw1;
            const float v11 = static_cast<float>(sprite.GetClippingRectangle().GetTop())    / th1;
            const float u12 = static_cast<float>(sprite.GetClippingRectangle().GetRight())  / tw1;
            const float v12 = static_cast<float>(sprite.GetClippingRectangle().GetBottom()) / th1;
            const float u21 = static_cast<float>(sprite.GetClippingRectangle().GetLeft())   / tw2;
            const float v21 = static_cast<float>(sprite.GetClippingRectangle().GetTop())    / th2;
            const float u22 = static_cast<float>(sprite.GetClippingRectangle().GetRight())  / tw2;
            const float v22 = static_cast<float>(sprite.GetClippingRectangle().GetBottom()) / th2;
            const float w  = static_cast<float>(sprite.GetClippingRectangle().Width);
            const float h  = static_cast<float>(sprite.GetClippingRectangle().Height);
            const int index = cachedNumberOfQuads * VerticesPerQuad;

            const D3DXVECTOR3 d3dScale = D3DXVECTOR3(scale.X, scale.Y, 1.0f);
            const D3DXVECTOR3 d3dTranslation = D3DXVECTOR3(position.X - 0.5f, position.Y - 0.5f, position.Z - 0.5f);
            D3DXQUATERNION d3dRotation;
            D3DXQuaternionRotationYawPitchRoll(&d3dRotation, rotation.Y, rotation.X, rotation.Z);

            D3DXMATRIX localTransform;
            D3DXMatrixTransformation(&localTransform, nullptr, nullptr, &d3dScale, nullptr, &d3dRotation, &d3dTranslation);
            D3DXVECTOR3 v[4] = 
            {
                D3DXVECTOR3(0.0f - sprite.GetOrigin().X, 0.0f - sprite.GetOrigin().Y, 0.0f),
                D3DXVECTOR3(w    - sprite.GetOrigin().X, 0.0f - sprite.GetOrigin().Y, 0.0f),
                D3DXVECTOR3(0.0f - sprite.GetOrigin().X, h    - sprite.GetOrigin().Y, 0.0f),
                D3DXVECTOR3(w    - sprite.GetOrigin().X, h    - sprite.GetOrigin().Y, 0.0f),
            };
            D3DXVECTOR4 transformed[sizeof(v) / sizeof(v[0])];
            D3DXVec3TransformArray(&transformed[0], sizeof(D3DXVECTOR4), &v[0], sizeof(D3DXVECTOR3), &localTransform, sizeof(v) / sizeof(v[0]));

            lockedVertices[index + 0] = Vertex(transformed[0], d3dColor, D3DXVECTOR2(u11, v11), D3DXVECTOR2(u21, v21));
            lockedVertices[index + 1] = Vertex(transformed[1], d3dColor, D3DXVECTOR2(u12, v11), D3DXVECTOR2(u22, v21));
            lockedVertices[index + 2] = Vertex(transformed[2], d3dColor, D3DXVECTOR2(u11, v12), D3DXVECTOR2(u21, v22));
            lockedVertices[index + 3] = Vertex(transformed[3], d3dColor, D3DXVECTOR2(u12, v12), D3DXVECTOR2(u22, v22));

            cachedTexture = sprite.GetTexture();
            cachedNumberOfQuads++;
        }

        Flush(true);

        d3dDevice->SetFVF(Vertex::FVF);
        d3dDevice->SetTexture(1, nullptr);
        d3dDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
        d3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
    }

    template <typename IteratorType> void SpriteRenderer::DrawLinesTemplate(IteratorType begin, IteratorType end, Color color)
    {
        if (begin == end)
            return;

        Flush(true);

        const D3DCOLOR d3dColor = color.ToARGB();

        int index = 0;
        int numberOfLines = 0;
        const Vector3 p = (*begin++);
        lockedVertices[index++] = Vertex(D3DXVECTOR4(p.X, p.Y, p.Z, 1.0f), d3dColor, D3DXVECTOR2(0.0f, 0.0f));
        for (IteratorType it = begin; it != end; it++, numberOfLines++)
            lockedVertices[index++] = Vertex(D3DXVECTOR4((*it).X, (*it).Y, (*it).Z, 1.0f), d3dColor, D3DXVECTOR2(0.0f, 0.0f));

        if (numberOfLines == 0)
            return;

        if (lockedVertices)
        {
            lockedVertices = nullptr;
            vb->Unlock();
        }

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();
        d3dDevice->SetTexture(0, nullptr);
        d3dDevice->DrawPrimitive(D3DPT_LINESTRIP, 0, numberOfLines);
        vb->Lock(0, quadCapacity * sizeof(Vertex) * VerticesPerQuad, reinterpret_cast<void**>(&lockedVertices), D3DLOCK_DISCARD);
    }

    void SpriteRenderer::DrawLine(Vector3 start, Vector3 end, Color color)
    {
        const Vector3 p[] = { start, end };
        DrawLinesTemplate(&p[0], &p[sizeof(p) / sizeof(p[0])], color);
    }

    void SpriteRenderer::DrawLines(const std::vector<Vector3>& points, Color color)
    {
        DrawLinesTemplate(points.begin(), points.end(), color);
    }

    void SpriteRenderer::DrawLines(const std::list<Vector3>&   points, Color color)
    {
        DrawLinesTemplate(points.begin(), points.end(), color);
    }

    void SpriteRenderer::DrawRectangle(const Rectangle& rectangle, Color color)
    {
        const Vector3 p[] = { Vector3(rectangle.GetLeft(),  rectangle.GetTop(), 0),
                              Vector3(rectangle.GetRight(), rectangle.GetTop(), 0),
                              Vector3(rectangle.GetRight(), rectangle.GetBottom(), 0),
                              Vector3(rectangle.GetLeft(),  rectangle.GetBottom(), 0),
                              Vector3(rectangle.GetLeft(),  rectangle.GetTop(), 0) };

        DrawLinesTemplate(&p[0], &p[sizeof(p) / sizeof(p[0])], color);
    }

    void SpriteRenderer::DrawRectangle(const RectangleF& rectangle, Color color)
    {
        const Vector3 p[] = { Vector3(rectangle.GetLeft(),  rectangle.GetTop(), 0.0f),
                              Vector3(rectangle.GetRight(), rectangle.GetTop(), 0.0f),
                              Vector3(rectangle.GetRight(), rectangle.GetBottom(), 0.0f),
                              Vector3(rectangle.GetLeft(),  rectangle.GetBottom(), 0.0f),
                              Vector3(rectangle.GetLeft(),  rectangle.GetTop(), 0.0f) };

        DrawLinesTemplate(&p[0], &p[sizeof(p) / sizeof(p[0])], color);
    }

    void SpriteRenderer::DrawString(Vector2 position, FontPtr font, const String& text)
    {
        DrawString(position, FontString(font, text));
    }

    void SpriteRenderer::DrawString(Vector2 position, FontPtr font, const String& text, float length, float boundary)
    {
        DrawString(position, FontString(font, text), length, boundary);
    }

    void SpriteRenderer::DrawString(Vector2 position, const FontString& fontString)
    {
        DrawString(position, fontString, static_cast<float>(fontString.GetRegularGlyphs().size()), NumericLimits::MaxFloat);
    }

    void SpriteRenderer::DrawString(Vector2 position, const FontString& fontString, float length, float boundary)
    {
        Flush(true);

        IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
        d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);

        d3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
        d3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
        d3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

        TypingContext context(fontString, boundary);
        float remainingLength = length;

        if (fontString.GetFont()->GetStrokeSize() > 0.0f)
        {
            const Color strokeColor = fontString.GetFont()->GetStrokeColor();
            while (context.MoveNext() && remainingLength > 0.0f)
            {
                const Glyph* glyph = context.GetStrokedGlyph();
                if (glyph->GetTexture())
                {
                    const Color drawingColor = Color(strokeColor.R, strokeColor.G, strokeColor.B,
                                                     static_cast<byte>(static_cast<float>(strokeColor.A) * Math::Min(remainingLength, 1.0f)));
                    const Vector2 drawingPosition = position + context.GetPosition() + glyph->GetBitmapOffset();
                    Draw(Vector3(drawingPosition, 0.0f), Vector3::Zero, Vector2::One, glyph->GetTexture(), glyph->GetClippingRectangle(), Vector2::Zero, drawingColor);
                }

                remainingLength -= 1.0f;
            }

            context.Reset();
            remainingLength = length;
        }

        const Color color = fontString.GetFont()->GetColor();
        while (context.MoveNext() && remainingLength > 0.0f)
        {
            const Glyph* glyph = context.GetRegularGlyph();
            if (glyph->GetTexture())
            {
                const Color drawingColor = Color(color.R, color.G, color.B,
                                                 static_cast<byte>(static_cast<float>(color.A) * Math::Min(remainingLength, 1.0f)));
                const Vector2 drawingPosition = position + context.GetPosition() + glyph->GetBitmapOffset();
                Draw(Vector3(drawingPosition, 0.0f), Vector3::Zero, Vector2::One, glyph->GetTexture(), glyph->GetClippingRectangle(), Vector2::Zero, drawingColor);
            }
            
            remainingLength -= 1.0f;
        }

        Flush(true);

        d3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
        d3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
        d3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
        d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
        d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
    }

    //void SpriteRenderer::Draw(Vector2 position, Color color, Texture2DPtr texture, const Rectangle& clippingRectangle)
    //{
    //    Flush(true);

    //    const D3DCOLOR d3dColor = color.ToARGB();
    //    const float tw = static_cast<float>(texture->GetWidth());
    //    const float th = static_cast<float>(texture->GetHeight());
    //    const float u1 = static_cast<float>(clippingRectangle.GetLeft())   / tw;
    //    const float v1 = static_cast<float>(clippingRectangle.GetTop())    / th;
    //    const float u2 = static_cast<float>(clippingRectangle.GetRight())  / tw;
    //    const float v2 = static_cast<float>(clippingRectangle.GetBottom()) / th;
    //    const float w  = static_cast<float>(clippingRectangle.Width);
    //    const float h  = static_cast<float>(clippingRectangle.Height);
    //    const int index = cachedNumberOfQuads * VerticesPerQuad;

    //    D3DXVECTOR4 v[4] = 
    //    {
    //        D3DXVECTOR4(0.0f + position.X, 0.0f + position.Y, 0.0f, 1.0f),
    //        D3DXVECTOR4(w    + position.X, 0.0f + position.Y, 0.0f, 1.0f),
    //        D3DXVECTOR4(0.0f + position.X, h    + position.Y, 0.0f, 1.0f),
    //        D3DXVECTOR4(w    + position.X, h    + position.Y, 0.0f, 1.0f),
    //    };

    //    lockedVertices[index + 0] = Vertex(v[0], d3dColor, D3DXVECTOR2(u1, v2));
    //    lockedVertices[index + 1] = Vertex(v[1], d3dColor, D3DXVECTOR2(u2, v2));
    //    lockedVertices[index + 2] = Vertex(v[2], d3dColor, D3DXVECTOR2(u1, v1));
    //    lockedVertices[index + 3] = Vertex(v[3], d3dColor, D3DXVECTOR2(u2, v1));

    //    cachedTexture = texture;
    //    cachedNumberOfQuads = 1;

    //    IDirect3DDevice9* d3dDevice = graphicsDevice->GetD3DDevice();
    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);

    //    d3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
    //    d3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    //    d3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

    //    Flush(true);

    //    d3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
    //    d3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
    //    d3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
    //    d3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
    //}

    void SpriteRenderer::CreateVertexAndIndexBuffer(int size)
    {
        HKAssert(size >= 0);

        CheckedRelease(ib);
        CheckedRelease(vb);
        quadCapacity = size;

        if (size == 0)
            return;

        HRESULT result = D3D_OK;

        const int vbSize = sizeof(Vertex) * VerticesPerQuad * size;
        const int ibSize = sizeof(WORD) * IndicesPerQuad * size;
        
        result = graphicsDevice->GetD3DDevice()->CreateVertexBuffer(vbSize, D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, Vertex::FVF, D3DPOOL_DEFAULT, &vb, nullptr);
        result = graphicsDevice->GetD3DDevice()->CreateIndexBuffer(ibSize,  D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib, nullptr);
        if (result == D3D_OK)
        {
            WORD* indices = nullptr;
            if (ib->Lock(0, ibSize, reinterpret_cast<void**>(&indices), 0) == D3D_OK)
            {
                const int numberOfIndices = IndicesPerQuad * size;
                for (WORD i = 0, v = 0; i < numberOfIndices; i += IndicesPerQuad, v += VerticesPerQuad)
                {
                    indices[i + 0] = v + 0;
                    indices[i + 1] = v + 1;
                    indices[i + 2] = v + 2;
                    indices[i + 3] = v + 3;
                    indices[i + 4] = v + 2;
                    indices[i + 5] = v + 1;
                }
                ib->Unlock();
            }
            else
                throw std::runtime_error("ib->Lock(0, ibSize, reinterpret_cast<void**>(&indices), 0) != D3D_OK");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    SpriteRenderer::Vertex::Vertex(D3DXVECTOR3 position, D3DCOLOR color, D3DXVECTOR2 texture)
        : Position(position),
          Color(color),
          Texture1(texture),
          Texture2(texture)
    {
    }

    SpriteRenderer::Vertex::Vertex(D3DXVECTOR4 position, D3DCOLOR color, D3DXVECTOR2 texture)
        : Position(position.x, position.y, position.z),
          Color(color),
          Texture1(texture),
          Texture2(texture)
    {
    }

    SpriteRenderer::Vertex::Vertex(D3DXVECTOR3 position, D3DCOLOR color, D3DXVECTOR2 texture1, D3DXVECTOR2 texture2)
        : Position(position),
          Color(color),
          Texture1(texture1),
          Texture2(texture2)
    {
    }

    SpriteRenderer::Vertex::Vertex(D3DXVECTOR4 position, D3DCOLOR color, D3DXVECTOR2 texture1, D3DXVECTOR2 texture2)
        : Position(position.x, position.y, position.z),
          Color(color),
          Texture1(texture1),
          Texture2(texture2)
    {
    }   

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    SpriteRenderer::OldRenderState::OldRenderState(D3DRENDERSTATETYPE state, DWORD value)
        : State(state), Value(value)
    {
    }

    SpriteRenderer::OldTextureStageState::OldTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value)
        : Stage(stage), Type(type), Value(value)
    {
    }

    SpriteRenderer::OldSamplerState::OldSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value)
        : Sampler(sampler), Type(type), Value(value)
    {
    }
}
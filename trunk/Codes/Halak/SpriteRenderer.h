#pragma once
#ifndef __HALAK_SPRITERENDERER_H__
#define __HALAK_SPRITERENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Matrix4.h>
#   include <Halak/Vector2.h>
#   include <Halak/Vector3.h>
#   include <list>
#   include <stack>
#   include <vector>
#   include <d3dx9.h>

    namespace Halak
    {
        class SpriteRenderer : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('S', 'P', 'R', 'R');
            public:
                SpriteRenderer(GraphicsDevice* graphicsDevice);
                virtual ~SpriteRenderer();

                void Push(const Matrix4& transform);
                void Pop();

                const Matrix4& GetTransform() const;

                void Begin();
                void Begin(float fieldOfView);
                void Draw(Vector3 position, Vector3 rotation, Vector2 scale, Texture2DPtr texture, const Rectangle& clippingRectangle, Color tint);
                void Draw(Vector3 position, Vector3 rotation, Vector2 scale, Texture2DPtr texture, const Rectangle& clippingRectangle, Vector2 origin, Color tint);
                void Draw(Vector3 position, Vector3 rotation, Vector2 scale, const Sprite& sprite, Color tint);
                void Draw(Vector3 position, Vector3 rotation, Vector2 scale, const Sprite& sprite, Color tint, Texture2DPtr opacityMap);
                void DrawLine(Vector3 start, Vector3 end, Color color);
                void DrawLines(const std::vector<Vector3>& points, Color color);
                void DrawLines(const std::list<Vector3>&   points, Color color);
                void DrawRectangle(const Rectangle& rectangle, Color color);

                void DrawString(Vector2 position, FontPtr font, const String& text);
                void DrawString(Vector2 position, FontPtr font, const String& text, float length, float boundary);
                void DrawString(Vector2 position, const FontString& fontString);
                void DrawString(Vector2 position, const FontString& fontString, float length, float boundary);
                void End();

            private:
                void BeginActually();
                void Flush(bool relock);

                template <typename IteratorType> void DrawLinesTemplate(IteratorType begin, IteratorType end, Color color);

                void CreateVertexAndIndexBuffer(int size);

                struct Vertex
                {
                    D3DXVECTOR3 Position;
                    D3DCOLOR    Color;
                    D3DXVECTOR2 Texture1;
                    D3DXVECTOR2 Texture2;

                    Vertex(D3DXVECTOR3 position, D3DCOLOR color, D3DXVECTOR2 texture);
                    Vertex(D3DXVECTOR4 position, D3DCOLOR color, D3DXVECTOR2 texture);
                    Vertex(D3DXVECTOR3 position, D3DCOLOR color, D3DXVECTOR2 texture1, D3DXVECTOR2 texture2);
                    Vertex(D3DXVECTOR4 position, D3DCOLOR color, D3DXVECTOR2 texture1, D3DXVECTOR2 texture2);

                    static const DWORD FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1;
                    static const DWORD DoubleTexturedFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX2;
                };

            private:
                GraphicsDevice* graphicsDevice;
            
                IDirect3DVertexBuffer9* vb;
                IDirect3DIndexBuffer9*  ib;
                int quadCapacity;

                Vertex* lockedVertices;

                std::stack<Matrix4> worldTransforms;

                Vector3 cameraPosition;
                Texture2DPtr   cachedTexture;
                int            cachedNumberOfQuads;

                static const unsigned short TrianglesPerQuad;
                static const unsigned short VerticesPerQuad;
                static const unsigned short IndicesPerQuad;

            private:
                 struct OldRenderState
                 {
                     D3DRENDERSTATETYPE State;
                     DWORD Value;

                     OldRenderState(D3DRENDERSTATETYPE state, DWORD value);
                 };

                 struct OldTextureStageState
                 {
                     DWORD Stage;
                     D3DTEXTURESTAGESTATETYPE Type;
                     DWORD Value;

                     OldTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);
                 };

                 struct OldSamplerState
                 {
                     DWORD Sampler;
                     D3DSAMPLERSTATETYPE Type;
                     DWORD Value;

                     OldSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value);
                 };

                 std::deque<OldRenderState>       oldRenderStates;
                 std::deque<OldTextureStageState> oldTextureStageStates;
                 std::deque<OldSamplerState>      oldSamplerStates;
        };
    }

#endif
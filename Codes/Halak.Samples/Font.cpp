#include <Halak.Samples/Samples.h>
#include <Halak/Colors.h>
#include <Halak/Font.h>
#include <Halak/FontLibrary.h>
#include <Halak/GameFramework.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/Glyph.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Texture2D.h>
#include <Halak/UIHandledDrawingContext.h>
#include <Halak/UIFixedFrame.h>
#include <Halak/UIRenderer.h>
#include <Halak/UISimpleDomain.h>
#include <Halak/UIWindow.h>
using namespace Halak;

class FontSampleApp : public GameFramework
{
    UIRenderer* uiRenderer;
    UIWindowPtr uiRoot;
    FontPtr font;

    virtual void Initialize()
    {
        GameFramework::Initialize();
        GetWindow()->SetTitle("Font - Halak Sample");
        GetWindow()->MoveToScreenCenter();

        FontLibrary* fontLibrary = new FontLibrary(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(fontLibrary);
        UISimpleDomain* uiDomain = new UISimpleDomain();
        GetStructure()->GetRoot()->AttachChild(uiDomain);
        uiRenderer = new UIRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(uiRenderer);

        uiRoot = new UIWindow();
        const Point window = GetGraphicsDevice()->GetWindow()->GetSize();
        uiRoot->SetFrame(new UIFixedFrame(RectangleF(0, 0, window.X, window.Y)));
        uiDomain->SetRoot(uiRoot);

        font = new Font(fontLibrary);
        font->SetFace("malgun.ttf");
        font->SetSize(30.0f);
        font->SetStrokeSize(4.0f);
        font->SetStrokeColor(Colors::White);
    }

    virtual void Finalize()
    {
        uiRoot.Reset();
        GameFramework::Finalize();
    }

    virtual void Update(float dt, uint timestamp)
    {
        GameFramework::Update(dt, timestamp);
    }

    virtual void Draw()
    {
        GetGraphicsDevice()->Clear();

        struct Handler : UIHandledDrawingContext::IHandler
        {
            Font* font;

            virtual void OnEnded(UIHandledDrawingContext& context)
            {
                context.DrawString(Vector2(100.0f, 500.0f), font, "신동림입니다");

                const Font::GlyphDictionary& glyphs1 = font->GetCachedRegularGlyphs();
                const Font::GlyphDictionary& glyphs2 = font->GetCachedStrokedGlyphs();
                const Glyph* glyph1 = (*glyphs1.find(L'신')).second;
                const Glyph* glyph2 = (*glyphs2.find(L'신')).second;
                context.Draw(Vector2::Zero, glyph1->GetTexture());
                context.Draw(Vector2(glyph1->GetTexture()->GetWidth(), 0), glyph2->GetTexture());
            }
        };

        Handler handler;
        handler.font = font;
        UIHandledDrawingContext context(uiRenderer);
        context.SetHandler(&handler);
        context.Draw(uiRoot);
    }
};

void Halak::Samples::FontSample(const std::vector<const char*>& /*args*/)
{
    FontSampleApp app;
    app.Run();
}
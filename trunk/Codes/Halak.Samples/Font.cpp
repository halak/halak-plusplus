#include <Halak.Samples/Samples.h>
#include <Halak/Font.h>
#include <Halak/FreeType.h>
#include <Halak/GameFramework.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
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

    virtual void Initialize()
    {
        GameFramework::Initialize();
        GetWindow()->SetTitle("Font - Halak Sample");
        GetWindow()->MoveToScreenCenter();

        FreeType* freeType = new FreeType(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(freeType);
        UISimpleDomain* uiDomain = new UISimpleDomain();
        GetStructure()->GetRoot()->AttachChild(uiDomain);
        uiRenderer = new UIRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(uiRenderer);

        uiRoot = new UIWindow();
        const Point window = GetGraphicsDevice()->GetWindow()->GetSize();
        uiRoot->SetFrame(new UIFixedFrame(RectangleF(0, 0, window.X, window.Y)));
        uiDomain->SetRoot(uiRoot);
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
            protected:
                virtual void OnEnded(UIHandledDrawingContext& context)
                {
                }
        };

        Handler handler;
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
#include <Halak.Samples/Samples.h>
#include <Halak/GameFramework.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Keyboard.h>
#include <Halak/KeyboardState.h>
#include <Halak/Mouse.h>
#include <Halak/SourceTexture2D.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/UIAlignedFrame.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFixedFrame.h>
#include <Halak/UIImage.h>
#include <Halak/UIKeyboardEventDispatcher.h>
#include <Halak/UIMarkupText.h>
#include <Halak/UIMouseEventDispatcher.h>
#include <Halak/UIRenderer.h>
#include <Halak/UISimpleWindowTarget.h>
#include <Halak/UISprite.h>
#include <Halak/UIWindow.h>
using namespace Halak;

class UISampleApp : public GameFramework
{
    Keyboard* keyboard;
    SpriteRenderer* spriteRenderer;
    UIRenderer* uiRenderer;
    UIWindowPtr root;
    UISpritePtr sprite;

    virtual void Initialize()
    {
        GameFramework::Initialize();
        GetWindow()->SetTitle("UI - Halak Sample");
        GetWindow()->MoveToScreenCenter();

        Mouse* mouse = new Mouse(GetWindow());
        GetStructure()->GetRoot()->AttachChild(mouse);
        keyboard = new Keyboard(GetWindow());
        GetStructure()->GetRoot()->AttachChild(keyboard);

        spriteRenderer = new SpriteRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(spriteRenderer);
        //uiRenderer = new UIRenderer(spriteRenderer);
        //GetStructure()->GetRoot()->AttachChild(uiRenderer);

        //UIMarkupText t1 = "My name is shin";
        //UIMarkupText t2 = "My name \n is shin";
        //UIMarkupText t3 = "Hello world |aaaaaa| shin fff ";
        //UIMarkupText t4 = "Character [tex:1111111?sss=30] ffff";
        //UIMarkupText t5 = "Character [tex:1111111?sss=30&fff=50]";

        UISimpleWindowTarget* uiWindowTarget = new UISimpleWindowTarget();
        GetStructure()->GetRoot()->AttachChild(uiWindowTarget);
        UIKeyboardEventDispatcher* uiKeyboard = new UIKeyboardEventDispatcher();
        uiKeyboard->SetWindowTarget(uiWindowTarget);
        uiKeyboard->SetDevice(keyboard);
        GetStructure()->GetRoot()->AttachChild(uiKeyboard);
        UIMouseEventDispatcher* uiMouse = new UIMouseEventDispatcher();
        uiMouse->SetWindowTarget(uiWindowTarget);
        uiMouse->SetDevice(mouse);
        GetStructure()->GetRoot()->AttachChild(uiMouse);

        root = new UIWindow();
        const Point window = GetGraphicsDevice()->GetWindow()->GetSize();
        root->SetFrame(new UIFixedFrame(RectangleF(0, 0, window.X, window.Y)));
        sprite = new UISprite();
        sprite->SetFrame(new UIAlignedFrame(UIAlignedFrame::Center, Vector2::Zero, Vector2(100.0f, 100.0f)));
        sprite->SetImage(new UIImage("", Rectangle::Empty));
        Texture2DPtr texture = new SourceTexture2D(GetGraphicsDevice(), "RSS.png");
        sprite->GetImage()->SetRealTextureData(texture, Halak::Rectangle(0, 0, 256, 256));
        root->AddChild(sprite);

        uiWindowTarget->SetTarget(root);
    }

    virtual void Finalize()
    {
        sprite.Reset();
        root.Reset();
        GameFramework::Finalize();
    }

    virtual void Update(float dt, uint timestamp)
    {
        GameFramework::Update(dt, timestamp);
        ForceUpdateAllComponents(dt, timestamp);
    }

    virtual void Draw()
    {
        GetGraphicsDevice()->Clear();

        spriteRenderer->Begin();
        UIDrawingContext context(spriteRenderer);
        context.Draw(root);
        spriteRenderer->End();
    }
};

void Halak::Samples::UISample(const std::vector<const char*>& /*args*/)
{
    UISampleApp app;
    app.Run();
}
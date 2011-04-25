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
#include <Halak/UIButton.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFixedFrame.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIImage.h>
#include <Halak/UIKeyboardEventDispatcher.h>
#include <Halak/UIMarkupText.h>
#include <Halak/UIMouseEventDispatcher.h>
#include <Halak/UIRenderer.h>
#include <Halak/UISimpleDomain.h>
#include <Halak/UISprite.h>
#include <Halak/UIWindow.h>
using namespace Halak;

class UISampleApp : public GameFramework
{
    Keyboard* keyboard;
    SpriteRenderer* spriteRenderer;
    UIRenderer* uiRenderer;
    UIWindowPtr root;

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

        UISimpleDomain* uiDomain = new UISimpleDomain();
        GetStructure()->GetRoot()->AttachChild(uiDomain);
        UIKeyboardEventDispatcher* uiKeyboard = new UIKeyboardEventDispatcher();
        uiKeyboard->SetDomain(uiDomain);
        uiKeyboard->SetDevice(keyboard);
        GetStructure()->GetRoot()->AttachChild(uiKeyboard);
        UIMouseEventDispatcher* uiMouse = new UIMouseEventDispatcher();
        uiMouse->SetDomain(uiDomain);
        uiMouse->SetDevice(mouse);
        GetStructure()->GetRoot()->AttachChild(uiMouse);

        root = new UIWindow();
        const Point window = GetGraphicsDevice()->GetWindow()->GetSize();
        root->SetFrame(new UIFixedFrame(RectangleF(0, 0, window.X, window.Y)));

        {
        UIButtonPtr button = new UIButton();
        button->SetFrame(new UIAlignedFrame(UIAlignedFrame::Center, Vector2::Zero, Vector2(100.0f, 100.0f)));
        UISpritePtr sprite1 = new UISprite();
        sprite1->SetFrame(new UIFittedFrame());
        sprite1->SetImage(new UIImage("", Rectangle::Empty));
        sprite1->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite2 = new UISprite();
        sprite2->SetFrame(new UIFittedFrame());
        sprite2->SetImage(new UIImage("", Rectangle::Empty));
        sprite2->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_b.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite3 = new UISprite();
        sprite3->SetFrame(new UIFittedFrame());
        sprite3->SetImage(new UIImage("", Rectangle::Empty));
        sprite3->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_a.png"), Halak::Rectangle(0, 0, 256, 256));
        button->GetNormalWindow()->AddChild(sprite1);
        button->GetPushedWindow()->AddChild(sprite2);
        button->GetHoveringWindow()->AddChild(sprite3);
        root->AddChild(button);
        }
        {
        UIButtonPtr button = new UIButton();
        button->SetFrame(new UIAlignedFrame(UIAlignedFrame::Center, Vector2(50.0f, 50.0f), Vector2(100.0f, 100.0f)));
        UISpritePtr sprite1 = new UISprite();
        sprite1->SetFrame(new UIFittedFrame());
        sprite1->SetImage(new UIImage("", Rectangle::Empty));
        sprite1->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite2 = new UISprite();
        sprite2->SetFrame(new UIFittedFrame());
        sprite2->SetImage(new UIImage("", Rectangle::Empty));
        sprite2->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_b.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite3 = new UISprite();
        sprite3->SetFrame(new UIFittedFrame());
        sprite3->SetImage(new UIImage("", Rectangle::Empty));
        sprite3->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_a.png"), Halak::Rectangle(0, 0, 256, 256));
        button->GetNormalWindow()->AddChild(sprite1);
        button->GetPushedWindow()->AddChild(sprite2);
        button->GetHoveringWindow()->AddChild(sprite3);
        root->AddChild(button);
        }

        uiDomain->SetRoot(root);
    }

    virtual void Finalize()
    {
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
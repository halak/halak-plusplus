#include <Halak.Samples/Samples.h>
#include <Halak/Font.h>
#include <Halak/FreeType.h>
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
#include <Halak/UICheckBox.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFixedFrame.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIImage.h>
#include <Halak/UIKeyboardEventDispatcher.h>
#include <Halak/UILabel.h>
#include <Halak/UIMarkupText.h>
#include <Halak/UIMarkupTextBox.h>
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
        FreeType* freeType = new FreeType(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(freeType);
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
        root->SetFrame(new UIFixedFrame(RectangleF(100, 100, window.X - 200, window.Y - 200)));

        {
        UIButtonPtr button = new UIButton();
        button->SetFrame(new UIAlignedFrame(UIAlignedFrame::Center, Vector2(-300.0f, 0.0f), Vector2(100.0f, 100.0f)));
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
        UICheckBoxPtr button = new UICheckBox();
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
        UISpritePtr sprite4 = new UISprite();
        sprite4->SetFrame(new UIFittedFrame());
        sprite4->SetImage(new UIImage("", Rectangle::Empty));
        sprite4->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite5 = new UISprite();
        sprite5->SetFrame(new UIFittedFrame());
        sprite5->SetImage(new UIImage("", Rectangle::Empty));
        sprite5->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_b.png"), Halak::Rectangle(0, 0, 256, 256));
        UISpritePtr sprite6 = new UISprite();
        sprite6->SetFrame(new UIFittedFrame());
        sprite6->SetImage(new UIImage("", Rectangle::Empty));
        sprite6->GetImage()->SetRealTextureData(new SourceTexture2D(GetGraphicsDevice(), "RSS_a.png"), Halak::Rectangle(0, 0, 256, 256));
        button->GetNormalWindow()->AddChild(sprite1);
        button->GetPushedWindow()->AddChild(sprite2);
        button->GetHoveringWindow()->AddChild(sprite3);
        button->GetCheckedNormalWindow()->AddChild(sprite4);
        button->GetCheckedNormalWindow()->SetOpacity(0.5f);
        button->GetCheckedPushedWindow()->AddChild(sprite5);
        button->GetCheckedPushedWindow()->SetOpacity(0.5f);
        button->GetCheckedHoveringWindow()->AddChild(sprite6);
        button->GetCheckedHoveringWindow()->SetOpacity(0.5f);
        root->AddChild(button);
        }

        uiDomain->SetRoot(root);

        FontPtr font = new Font(freeType);
        font->SetFace("malgun.ttf");
        font->SetSize(20.0f);
        UIMarkupTextBoxPtr label = new UIMarkupTextBox();
        label->SetFrame(new UIAlignedFrame(UIAlignedFrame::RightTop, Vector2(50.0f, 50.0f), Vector2(100.0f, 100.0f)));
        label->SetFont(font);
        label->SetText(UIMarkupText("HELLO|#FF0000|HELLO"));
        root->AddChild(label);
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
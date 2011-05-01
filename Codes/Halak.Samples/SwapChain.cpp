#include <Halak.Samples/Samples.h>
#include <Halak/Colors.h>
#include <Halak/DisplaySwapChain.h>
#include <Halak/Font.h>
#include <Halak/FreeType.h>
#include <Halak/GameFramework.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Math.h>
#include <Halak/SpriteRenderer.h>
using namespace Halak;

class SwapChainSampleApp : public GameFramework
{
    GameWindow* otherWindow;
    DisplaySwapChain* otherSwapChain;
    FreeType* freeType;
    SpriteRenderer* spriteRenderer;

    FontPtr font;
    float textRotation;
    Vector2 textSize;

    virtual void Initialize()
    {
        GetWindow()->SetSize(Point(800, 600));
        GetWindow()->SetTitle("Mainwindow");
        GetWindow()->MoveToScreenCenter();

        GameFramework::Initialize();

        otherWindow = new GameWindow();
        otherWindow->SetSize(Point(200, 100));
        otherWindow->SetTitle("SubWindow");
        otherWindow->SetVisible(true);
        otherWindow->SetPosition(Point::Zero);
        GetStructure()->GetRoot()->AttachChild(otherWindow);

        otherSwapChain = new DisplaySwapChain(GetGraphicsDevice(), otherWindow);
        GetStructure()->GetRoot()->AttachChild(otherSwapChain);

        freeType = new FreeType(GetGraphicsDevice());
        spriteRenderer = new SpriteRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(freeType);
        GetStructure()->GetRoot()->AttachChild(spriteRenderer);

        font = new Font(freeType);
        font->SetFace("malgun.ttf");
        font->SetSize(20.0f);
        font->SetColor(Colors::Blue);

        textRotation = 0.0f;
        textSize = font->Measure("Hello");
    }

    virtual void Finalize()
    {
        font.Reset();
        GameFramework::Finalize();
    }

    virtual void Update(float dt, uint timestamp)
    {
        GameFramework::Update(dt, timestamp);
        textRotation += dt * Math::TwoPi;
    }

    virtual void Draw()
    {
        GetGraphicsDevice()->Clear();
        spriteRenderer->Begin();
        spriteRenderer->Push(Matrix4::Translation(Vector3(-textSize.X * 0.5f - 100.0f, -textSize.Y * 0.5f - 100.0f, 0.0f)) *
                             Matrix4::RotationZ(textRotation) *
                             Matrix4::Translation(Vector3(+textSize.X * 0.5f + 100.0f, +textSize.Y * 0.5f + 100.0f, 0.0f)));
        spriteRenderer->DrawString(Vector2(100.0f, 100.0f), font, "Hello");
        spriteRenderer->Pop();

        char fpsString[32] = { '\0', };
        _snprintf(fpsString, sizeof(fpsString), "%.4f", GetFPS());
        spriteRenderer->DrawString(Vector2(10.0f, 10.0f), font, fpsString);

        spriteRenderer->End();
        GameFramework::Draw();
    }

    virtual void EndDraw()
    {
        GameFramework::EndDraw();

        otherSwapChain->BeginDraw();
        GetGraphicsDevice()->Clear(Colors::YellowGreen);
        spriteRenderer->Begin();
        spriteRenderer->Push(Matrix4::Translation(Vector3(-textSize.X * 0.5f - 10.0f, -textSize.Y * 0.5f - 10.0f, 0.0f)) *
                             Matrix4::RotationZ(-textRotation) *
                             Matrix4::Translation(Vector3(+textSize.X * 0.5f + 10.0f, +textSize.Y * 0.5f + 10.0f, 0.0f)));
        spriteRenderer->DrawString(Vector2(10.0f, 10.0f), font, "Hello");
        spriteRenderer->Pop();
        spriteRenderer->End();
        otherSwapChain->EndDraw();
        otherSwapChain->Present();
    }
};

void Halak::Samples::SwapChainSample(const std::vector<const char*>& /*args*/)
{
    SwapChainSampleApp app;
    app.Run();
}
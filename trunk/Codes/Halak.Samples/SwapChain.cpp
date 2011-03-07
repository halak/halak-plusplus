#include <Halak.Samples/Samples.h>
#include <Halak/DisplaySwapChain.h>
#include <Halak/Font.h>
#include <Halak/FreeType.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/GameWindow.h>
using namespace Halak;

void Halak::Samples::SwapChainSample(const std::vector<const char*>& /*args*/)
{
    GameStructure* componentMap = new GameStructure();
    GameWindow* window1 = new GameWindow();
    GameWindow* window2 = new GameWindow();
    window1->SetSize(Point(800, 600));
    window2->SetSize(Point(200, 100));
    window1->SetTitle("Mainwindow");
    window2->SetTitle("SubWindow");
    window1->MoveToScreenCenter();
    window2->SetPosition(Point::Zero);
    componentMap->GetRoot()->AttachChild(window1);
    componentMap->GetRoot()->AttachChild(window2);
    GraphicsDevice* graphicsDevice = new GraphicsDevice();
    graphicsDevice->SetFullscreen(false);
    graphicsDevice->SetWindow(window1);
    componentMap->GetRoot()->AttachChild(graphicsDevice);

    DisplaySwapChain* swapChain = new DisplaySwapChain(graphicsDevice, window2);
    componentMap->GetRoot()->AttachChild(swapChain);

    FreeType* freeType = new FreeType(graphicsDevice);
    SpriteRenderer* spriteRenderer = new SpriteRenderer(graphicsDevice);
    componentMap->GetRoot()->AttachChild(freeType);
    componentMap->GetRoot()->AttachChild(spriteRenderer);

    FontPtr font(new Font(freeType));
    font->SetFace("malgun.ttf");
    font->SetSize(20.0f);
    font->SetColor(Color::Blue);

    window1->SetVisible(true);
    window2->SetVisible(true);

    float rotation = 0.0f;
    Vector2 size = font->Measure("Hello");
    MSG message;
    for (;;)
    {
        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);

            if (message.message == WM_QUIT)
                break;
        }
        else
        {
            rotation += 0.01f;

            graphicsDevice->BeginDraw();
            graphicsDevice->Clear();
            spriteRenderer->Begin();
            spriteRenderer->Push(Matrix4::Translation(Vector3(-size.X / 2.0f - 100.0f, -size.Y / 2.0f - 100.0f, 0.0f)) *
                                 Matrix4::RotationZ(rotation) *
                                 Matrix4::Translation(Vector3(+size.X / 2.0f + 100.0f, +size.Y / 2.0f + 100.0f, 0.0f)));
            spriteRenderer->DrawString(Vector2(100.0f, 100.0f), font, "Hello");
            spriteRenderer->Pop();
            spriteRenderer->End();
            graphicsDevice->EndDraw();
            graphicsDevice->Present();

            swapChain->BeginDraw();
            graphicsDevice->Clear(Color::YellowGreen);
            spriteRenderer->Begin();
            spriteRenderer->Push(Matrix4::Translation(Vector3(-size.X / 2.0f - 10.0f, -size.Y / 2.0f - 10.0f, 0.0f)) *
                                 Matrix4::RotationZ(-rotation) *
                                 Matrix4::Translation(Vector3(+size.X / 2.0f + 10.0f, +size.Y / 2.0f + 10.0f, 0.0f)));
            spriteRenderer->DrawString(Vector2(10.0f, 10.0f), font, "Hello");
            spriteRenderer->Pop();
            spriteRenderer->End();
            swapChain->EndDraw();
            swapChain->Present();
            Sleep(1);
        }
    }

    font.reset();
    delete componentMap;
}
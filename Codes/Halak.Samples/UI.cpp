#include <Halak.Samples/Samples.h>
#include <Halak/GameFramework.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/UIMarkupText.h>
using namespace Halak;

class UISampleApp : public GameFramework
{
    virtual void Initialize()
    {
        GameFramework::Initialize();
        GetWindow()->SetTitle("UI - Halak Sample");
        GetWindow()->MoveToScreenCenter();

        UIMarkupText t1 = "My name is shin";
        UIMarkupText t2 = "My name \n is shin";
        UIMarkupText t3 = "Hello world |aaaaaa| shin fff ";
        UIMarkupText t4 = "Character [tex:1111111?sss=30] ffff";
        UIMarkupText t5 = "Character [tex:1111111?sss=30&fff=50]";

        int i = 0;
        i = 0;
        i = 0;
    }

    virtual void Finalize()
    {
        GameFramework::Finalize();
    }

    virtual void Update(float dt, uint timestamp)
    {
        GameFramework::Update(dt, timestamp);
    }

    virtual void Draw()
    {
        GetGraphicsDevice()->Clear();
    }
};

void Halak::Samples::UISample(const std::vector<const char*>& /*args*/)
{
    UISampleApp app;
    app.Run();
}
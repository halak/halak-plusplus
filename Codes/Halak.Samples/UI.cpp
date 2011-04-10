#include <Halak.Samples/Samples.h>
#include <Halak/GameFramework.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
using namespace Halak;

class UISampleApp : public GameFramework
{
    virtual void Initialize()
    {
        GameFramework::Initialize();
        GetWindow()->SetTitle("UI - Halak Sample");
        GetWindow()->MoveToScreenCenter();
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
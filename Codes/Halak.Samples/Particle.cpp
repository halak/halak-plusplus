#include <Halak.Samples/Samples.h>
#include <Halak/Clock.h>
#include <Halak/EvaluableFloatConstant.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/SimpleParticleEmitter.h>
#include <Halak/SourceTexture2D.h>
#include <Halak/SpatialObject.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/ParticleSpawnPoints.h>
#include <Halak/BatchCommand.h>
using namespace Halak;

void Halak::Samples::ParticleSample(const std::vector<const char*>& /*args*/)
{
    GameStructure* componentMap = new GameStructure();
    GameWindow* window = new GameWindow();
    window->SetSize(Point(800, 600));
    window->SetTitle("Particle - Halak Sample");
    window->MoveToScreenCenter();
    componentMap->GetRoot()->AttachChild(window);
    GraphicsDevice* graphicsDevice = new GraphicsDevice();
    graphicsDevice->SetFullscreen(false);
    graphicsDevice->SetWindow(window);
    componentMap->GetRoot()->AttachChild(graphicsDevice);

    SpriteRenderer* spriteRenderer = new SpriteRenderer(graphicsDevice);
    componentMap->GetRoot()->AttachChild(spriteRenderer);

    Texture2DPtr texture(new SourceTexture2D(graphicsDevice, "Particle.png"));

    SimpleParticleEmitterPtr emitter(new SimpleParticleEmitter());
    emitter->SetOrigin(ISpatialPtr(new SpatialObject(Vector3(400.0f, 300.0f, 0.0f))));
    emitter->SetSpawnPoint(new ParticleSpawnPoint());
    emitter->SetSpawnPeriod(IFloatEvaluablePtr(new EvaluableFloatConstant(0.01f)));
    emitter->SetLinearVelocity1(Vector3(+200.0f, +200.0f, +0.0f));
    emitter->SetLinearVelocity2(Vector3(+300.0f, +300.0f, +0.0f));
    emitter->SetLinearAccelerationForce1(-120.0f);
    emitter->SetLinearAccelerationForce2(-100.0f);
    emitter->SetEndTint1(Color(255, 0, 255, 0));
    emitter->SetEndTint2(Color(0, 255, 0, 0));
    emitter->SetStrainVelocity1(Vector2(-0.8f, -0.8f));
    emitter->SetStrainVelocity2(Vector2(-0.9f, -0.9f));
    emitter->SetAngularVelocity1(-10.0f);
    emitter->SetAngularVelocity2(+10.0f);
    emitter->SetLifespan1(5.0f);
    emitter->SetLifespan2(8.0f);
    emitter->SetRatioKeepScale(true);

    SimpleParticleEmitter::SpriteCollection sprites;
    sprites.push_back(Sprite(texture, Vector2(16.0f, 16.0f)));
    emitter->SetSpritePalette(sprites);
    sprites.clear();

    window->SetVisible(true);

    uint timestamp = 0;
    float previousTime = 0.0f;
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
            const float currentTime = Clock::GetCurrent();
            emitter->Update(currentTime - previousTime, timestamp++);
            previousTime = currentTime;

            graphicsDevice->BeginDraw();
            graphicsDevice->Clear();
            spriteRenderer->Begin();
            const SimpleParticleEmitter::ParticleCollection& particles = emitter->GetParticles();
            for (SimpleParticleEmitter::ParticleCollection::const_reverse_iterator it = particles.rbegin(); it != particles.rend(); it++)
            {
                const SimpleParticle* item = (*it);
                spriteRenderer->Draw(item->Position, Vector3(0.0f, 0.0f, item->Rotation), item->Scale, item->SpriteInstance, item->Tint);
            }
            spriteRenderer->End();
            graphicsDevice->EndDraw();
            graphicsDevice->Present();
            Sleep(1);
        }
    }
    
    emitter.reset();
    texture.reset();

    delete componentMap;
}
#include <Halak.Samples/Samples.h>
#include <Halak/Clock.h>
#include <Halak/EvaluableFloatConstant.h>
#include <Halak/GameFramework.h>
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

class ParticleSampleApp : public GameFramework
{
    SpriteRenderer* spriteRenderer;
    SimpleParticleEmitterPtr emitter;
    Texture2DPtr texture;

    virtual void Initialize()
    {
        GameFramework::Initialize();

        spriteRenderer = new SpriteRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(spriteRenderer);

        texture = new SourceTexture2D(GetGraphicsDevice(), "Particle.png");

        emitter = new SimpleParticleEmitter();
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
    }

    virtual void Finalize()
    {
        emitter.Reset();
        texture.Reset();
        GameFramework::Finalize();
    }

    virtual void Update(float dt, uint timestamp)
    {
        GameFramework::Update(dt, timestamp);
        emitter->Update(dt, timestamp);
    }

    virtual void Draw()
    {
        GetGraphicsDevice()->Clear();
        spriteRenderer->Begin();
        const SimpleParticleEmitter::ParticleCollection& particles = emitter->GetParticles();
        for (SimpleParticleEmitter::ParticleCollection::const_reverse_iterator it = particles.rbegin(); it != particles.rend(); it++)
        {
            const SimpleParticle* item = (*it);
            spriteRenderer->Draw(item->Position, Vector3(0.0f, 0.0f, item->Rotation), item->Scale, item->SpriteInstance, item->Tint);
        }
        spriteRenderer->End();
        GameFramework::Draw();
    }
};

void Halak::Samples::ParticleSample(const std::vector<const char*>& /*args*/)
{
    ParticleSampleApp app;
    app.Run();
}
#include <Halak.Samples/Samples.h>
#include <Halak/Clock.h>
#include <Halak/ColorRangeSequence.h>
#include <Halak/EvaluableFloatSequence.h>
#include <Halak/EvaluableFloatRangeSequence.h>
#include <Halak/FloatSequence.h>
#include <Halak/FloatRangeSequence.h>
#include <Halak/GameFramework.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/SequentialParticleEmitter.h>
#include <Halak/SourceTexture2D.h>
#include <Halak/SpatialObject.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/SpriteSequence.h>
#include <Halak/ParticleSpawnPoints.h>
#include <Halak/Vector2RangeSequence.h>
#include <Halak/Vector3RangeSequence.h>
using namespace Halak;

class SequentialParticleApp : public GameFramework
{
    SpriteRenderer* spriteRenderer;
    Texture2DPtr texture;
    SequentialParticleEmitterPtr emitter;

    virtual void Initialize()
    {
        GameFramework::Initialize();

        GetWindow()->SetTitle("Particle - Halak Sample");
        GetWindow()->MoveToScreenCenter();

        spriteRenderer = new SpriteRenderer(GetGraphicsDevice());
        GetStructure()->GetRoot()->AttachChild(spriteRenderer);

        texture = new SourceTexture2D(GetGraphicsDevice(), "Particle.png");

        emitter = new SequentialParticleEmitter();
        FloatRangeSequencePtr lifespanSequence(new FloatRangeSequence());
        lifespanSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(4.1f, 5.5f), 2.0f));
        lifespanSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(3.1f, 3.5f), 1.0f));
        lifespanSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(0.1f, 0.5f), 3.0f));
        lifespanSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(1.1f, 1.5f), 3.0f));
        EvaluableFloatRangeSequencePtr lifespan(new EvaluableFloatRangeSequence());
        lifespan->SetLooped(true);
        lifespan->SetSource(lifespanSequence);
        emitter->SetLifespan(lifespan);
        FloatSequencePtr spawnPeriodSequence(new FloatSequence());
        spawnPeriodSequence->AddKeyframe(FloatKeyframe(2.0f, 2.0f));
        spawnPeriodSequence->AddKeyframe(FloatKeyframe(1.0f, 1.0f));
        spawnPeriodSequence->AddKeyframe(FloatKeyframe(0.05f, 2.0f));
        spawnPeriodSequence->AddKeyframe(FloatKeyframe(0.05f, 1.0f));
        spawnPeriodSequence->AddKeyframe(FloatKeyframe(1.0f, 3.0f));
        EvaluableFloatSequencePtr spawnPeriod(new EvaluableFloatSequence());
        spawnPeriod->SetSource(spawnPeriodSequence);
        spawnPeriod->SetLooped(true);
        emitter->SetOrigin(ISpatialPtr(new SpatialObject(Vector3(100.0f, 100.0f, 0.0f))));
        emitter->SetSpawnPoint(new ParticleSpawnPoint());
        emitter->SetSpawnPeriod(spawnPeriod);

        Vector3RangeSequencePtr velocitySequence(new Vector3RangeSequence());
        velocitySequence->AddKeyframe(Vector3RangeKeyframe(Vector3Range(Vector3(100.0f, 200.0f, 0.0f), Vector3(200.0f, 100.0f, 0.0f)), 1.0f));
        velocitySequence->AddKeyframe(Vector3RangeKeyframe(Vector3Range(Vector3(100.0f, 300.0f, 0.0f), Vector3(300.0f, 100.0f, 0.0f)), 1.0f));
        FloatRangeSequencePtr rotationSequence(new FloatRangeSequence());
        rotationSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(0.0f, 1.0f), 2.0f));
        rotationSequence->AddKeyframe(FloatRangeKeyframe(FloatRange(1.0f, 20.14f), 1.0f));
        Vector2RangeSequencePtr scaleSequence(new Vector2RangeSequence());
        scaleSequence->AddKeyframe(Vector2RangeKeyframe(Vector2Range(Vector2::One, Vector2::One), 1.0f));
        ColorRangeSequencePtr colorSequence(new ColorRangeSequence());
        colorSequence->AddKeyframe(ColorRangeKeyframe(ColorRange(Color::TransparentWhite, Color::TransparentWhite), 0.3f));
        colorSequence->AddKeyframe(ColorRangeKeyframe(ColorRange(Color::Red, Color::Blue), 1.0f));
        colorSequence->AddKeyframe(ColorRangeKeyframe(ColorRange(Color::Red, Color::Blue), 0.3f));
        colorSequence->AddKeyframe(ColorRangeKeyframe(ColorRange(Color::TransparentWhite, Color::TransparentWhite), 0.0f));

        emitter->SetLinearVelocitySequence(velocitySequence);
        emitter->SetRotationSequence(rotationSequence);
        emitter->SetScaleSequence(scaleSequence);
        emitter->SetTintSequence(colorSequence);

        SequentialParticleEmitter::SpriteSequenceCollection spriteSequences;
        spriteSequences.push_back(SpriteSequencePtr(new SpriteSequence()));
        spriteSequences.back()->AddKeyframe(SpriteKeyframe(Sprite(texture, Vector2(16.0f, 16.0f)), 1.0f));
        emitter->SetSpriteSequences(spriteSequences);
        spriteSequences.clear();
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
        const SequentialParticleEmitter::ParticleCollection& particles = emitter->GetParticles();
        for (SequentialParticleEmitter::ParticleCollection::const_reverse_iterator it = particles.rbegin(); it != particles.rend(); it++)
        {
            const SequentialParticle* item = (*it);
            spriteRenderer->Draw(item->Position, Vector3(0.0f, 0.0f, item->Rotation), item->Scale, item->SpriteInstance, item->Tint);
        }
        spriteRenderer->End();
        GameFramework::Draw();
    }
};

void Halak::Samples::SequentialParticleSample(const std::vector<const char*>& /*args*/)
{
    SequentialParticleApp app;
    app.Run();
}
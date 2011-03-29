#include <Halak/ParticleEffectEntity.h>
#include <Halak/ISpatial.h>
#include <Halak/ParticleEmitter.h>
#include <Halak/ParticleRenderer.h>
#include <Halak/PickingContext.h>

namespace Halak
{
    ParticleEffectEntity::ParticleEffectEntity()
        : EffectEntity()
    {
    }

    ParticleEffectEntity::ParticleEffectEntity(const String& name)
        : EffectEntity(name)
    {
    }

    ParticleEffectEntity::ParticleEffectEntity(const ParticleEffectEntity& original, CloningContext& context)
        : EffectEntity(original, context)
    {
    }

    ParticleEffectEntity::~ParticleEffectEntity()
    {
    }

    ParticleEffectEntity* ParticleEffectEntity::Clone() const
    {
        return static_cast<ParticleEffectEntity*>(ICloneable::Clone());
    }

    ParticleEffectEntity* ParticleEffectEntity::CloneWith(CloningContext& context) const
    {
        return new ParticleEffectEntity(*this, context);
    }

    void ParticleEffectEntity::Dispose()
    {
        EffectEntity::Dispose();
        emitter.Reset();
        renderer.Reset();
    }

    bool ParticleEffectEntity::Pick(PickingContext& context)
    {
        if (emitter == nullptr || emitter->GetOrigin() == nullptr)
            return false;

        const Vector3 p0 = emitter->GetOrigin()->GetPosition();
        const Vector3 p1 = context.GetRay().Origin;
        if (Vector3::GetDistanceSquared(p0, p1) < 8.0f * 8.0f)
            return context.Push(PickResult(0.0f, p1, -context.GetRay().Direction, DynamicCastTo<IPickable>(), Any::Null));
        else
            return false;
    }

    void ParticleEffectEntity::Update(float dt, uint timestamp)
    {
        if (emitter)
            emitter->Update(dt, timestamp);
    }

    void ParticleEffectEntity::Draw(DrawingContext& context)
    {
        if (renderer)
            renderer->Draw(context);
    }

    ParticleEmitterPtr ParticleEffectEntity::GetEmitter() const
    {
        return emitter;
    }

    void ParticleEffectEntity::SetEmitter(ParticleEmitterPtr value)
    {
        if (emitter != value)
        {
            ParticleEmitterPtr old;
            old.Swap(emitter);

            emitter = value;
            OnEmitterChanged(old);
        }
    }
    
    ParticleRendererPtr ParticleEffectEntity::GetRenderer() const
    {
        return renderer;
    }

    void ParticleEffectEntity::SetRenderer(ParticleRendererPtr value)
    {
        if (renderer != value)
        {
            ParticleRendererPtr old;
            old.Swap(renderer);

            renderer = value;
            OnRendererChanged(old);
        }
    }
               
    void ParticleEffectEntity::OnOriginChanged(ISpatialPtr /*old*/)
    {
        if (emitter && emitter->GetOrigin() != GetOrigin())
            emitter->SetOrigin(GetOrigin());
    }

    void ParticleEffectEntity::OnEmitterChanged(ParticleEmitterPtr /*old*/)
    {
        if (emitter)
        {
            if (emitter->GetOrigin())
                SetOrigin(emitter->GetOrigin());
            else
                emitter->SetOrigin(GetOrigin());
        }
    }

    void ParticleEffectEntity::OnRendererChanged(ParticleRendererPtr /*old*/)
    {
        if (renderer)
            renderer->SetTarget(emitter);
    }
}
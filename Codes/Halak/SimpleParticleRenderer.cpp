#include <Halak/PCH.h>
#include <Halak/SimpleParticleRenderer.h>
#include <Halak/Assert.h>
#include <Halak/DrawingContext.h>
#include <Halak/SimpleParticleEmitter.h>
#include <Halak/SpriteRenderer.h>
#include <stdexcept>

namespace Halak
{
    SimpleParticleRenderer::SimpleParticleRenderer()
    {
    }

    SimpleParticleRenderer::~SimpleParticleRenderer()
    {
    }

    void SimpleParticleRenderer::Draw(DrawingContext& context)
    {
        HKAssertDebug(context.GetSpriteRenderer());
        if (GetTargetPointee() == nullptr)
            return;

        SpriteRenderer* renderer = context.GetSpriteRenderer();
        const SimpleParticleEmitter* castedTarget = static_cast<const SimpleParticleEmitter*>(GetTargetPointee().GetPointee());
        const SimpleParticleEmitter::ParticleCollection& particles = castedTarget->GetParticles();
        for (SimpleParticleEmitter::ParticleCollection::const_reverse_iterator it = particles.rbegin(); it != particles.rend(); it++)
        {
            const SimpleParticle* item = (*it);
            renderer->Draw(item->Position, Vector3(0.0f, 0.0f, item->Rotation), item->Scale, item->SpriteInstance, item->Tint);
        }
    }

    void SimpleParticleRenderer::DrawDebugInformation(DrawingContext& context)
    {
        HKAssertDebug(context.GetSpriteRenderer());
        if (GetTargetPointee() == nullptr)
            return;

        SpriteRenderer* renderer = context.GetSpriteRenderer();
        const SimpleParticleEmitter* castedTarget = static_cast<const SimpleParticleEmitter*>(GetTargetPointee().GetPointee());
        const SimpleParticleEmitter::ParticleCollection& particles = castedTarget->GetParticles();
        //for (SimpleParticleEmitter::ParticleCollection::const_reverse_iterator it = particles.rbegin(); it != particles.rend(); it++)
        //{
        //    const SimpleParticle* item = (*it);
        //    renderer->Draw(item->Position, Vector3(0.0f, 0.0f, item->Rotation), item->Scale, item->SpriteInstance, item->Tint);
        //}
    }

    void SimpleParticleRenderer::OnTargetChanged(ParticleEmitterPtr old)
    {
        if (dynamic_cast<SimpleParticleEmitter*>(GetTargetPointee().GetPointee()) == nullptr)
            throw std::bad_typeid("SimpleParticleRenderer::OnTargetChanged(ParticleEmitterPtr)");
    }
}
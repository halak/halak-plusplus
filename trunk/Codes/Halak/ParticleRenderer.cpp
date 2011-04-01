#include <Halak/PCH.h>
#include <Halak/ParticleRenderer.h>
#include <Halak/ParticleEmitter.h>

namespace Halak
{
    ParticleRenderer::ParticleRenderer()
    {
    }

    ParticleRenderer::~ParticleRenderer()
    {
    }

    ParticleEmitterPtr ParticleRenderer::GetTargetPointee() const
    {
        return target;
    }

    void ParticleRenderer::SetTarget(ParticleEmitterPtr value)
    {
        if (target != value)
        {
            ParticleEmitterPtr old = target;

            target = value;

            OnTargetChanged(old);
        }
    }

    void ParticleRenderer::OnTargetChanged(ParticleEmitterPtr /*old*/)
    {
    }
}
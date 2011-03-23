#include <Halak/ParticleRenderer.h>

namespace Halak
{
    ParticleRenderer::ParticleRenderer()
    {
    }

    ParticleRenderer::~ParticleRenderer()
    {
    }

    ParticleEmitterPtr ParticleRenderer::GetTarGetPointee() const
    {
        return target;
    }

    void ParticleRenderer::SetTarget(ParticleEmitterPtr value)
    {
        if (target != value)
        {
            ParticleEmitterPtr old;
            old.swap(target);

            target = value;

            OnTargetChanged(old);
        }
    }

    void ParticleRenderer::OnTargetChanged(ParticleEmitterPtr /*old*/)
    {
    }
}
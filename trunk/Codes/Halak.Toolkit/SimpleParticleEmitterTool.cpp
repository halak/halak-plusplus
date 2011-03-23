#include <Halak.wxToolkit/SimpleParticleEmitterTool.h>
#include <Halak/DrawingContext.h>
#include <Halak/SimpleParticleEmitter.h>

namespace Halak
{
    namespace wxToolkit
    {
        SimpleParticleEmitterTool::SimpleParticleEmitterTool(ServiceTree* services)
            : ParticleEmitterTool(services)
        {
        }

        SimpleParticleEmitterTool::~SimpleParticleEmitterTool()
        {
        }

        void SimpleParticleEmitterTool::Draw(DrawingContext& context)
        {
            if (GetStatus() != Tool::ActiveStatus)
                return;
            if (target.IsAlive() == false)
                return;

            SpriteRenderer* renderer = context.GetSpriteRenderer();
        }

        SimpleParticleEmitterWeakPtr SimpleParticleEmitterTool::GetTarGetPointee() const
        {
            return target;
        }

        void SimpleParticleEmitterTool::SetTarget(SimpleParticleEmitterWeakPtr value)
        {
            target = value;
            ParticleEmitterTool::SetTarget(value);
        }
    }
}
#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/SimpleParticleEmitterTool.h>
#include <Halak/DrawingContext.h>
#include <Halak/SimpleParticleEmitter.h>
#include <Halak/Texture2D.h>

namespace Halak
{
    namespace Toolkit
    {
        SimpleParticleEmitterTool::SimpleParticleEmitterTool(GameStructure* structure)
            : ParticleEmitterTool(structure)
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

        SimpleParticleEmitterWeakPtr SimpleParticleEmitterTool::GetTargetPointee() const
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
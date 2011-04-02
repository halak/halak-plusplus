#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/ParticleEmitterTool.h>
#include <Halak/Assert.h>
#include <Halak/ParticleEmitter.h>

namespace Halak
{
    namespace Toolkit
    {
        ParticleEmitterTool::ParticleEmitterTool(GameStructure* structure)
            : structure(structure)
        {
        }
        
        ParticleEmitterTool::~ParticleEmitterTool()
        {
        }

        ParticleEmitterWeakPtr ParticleEmitterTool::GetTargetPointee() const
        {
            return target;
        }

        void ParticleEmitterTool::SetTarget(ParticleEmitterWeakPtr value)
        {
            target = value;
        }
    }
}
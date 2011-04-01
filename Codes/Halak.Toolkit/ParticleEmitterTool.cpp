#include <Halak.wxToolkit/ParticleEmitterTool.h>
#include <Halak/Assert.h>
#include <Halak/ParticleEmitter.h>

namespace Halak
{
    namespace wxToolkit
    {
        ParticleEmitterTool::ParticleEmitterTool(ServiceTree* services)
            : services(services)
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
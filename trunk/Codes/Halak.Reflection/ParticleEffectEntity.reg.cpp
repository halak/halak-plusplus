#include <Halak.Toolkit/PCH.h>
#include <Halak/ParticleEffectEntity.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void ParticleEffectEntity::__Startup__()
    {
        Class<ParticleEffectEntity>()
            .SetID(HKMakeFOURCC('P', 'T', 'E', 'T'), "Halak", "ParticleEffectEntity")
            .Inherits<EffectEntity>()
            .Inherits<IDrawable>();
    }
}
#include <Halak/ParticleEffectEntity.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

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
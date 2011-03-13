#include <Halak/EffectEntity.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void EffectEntity::__Startup__()
    {
        Class<EffectEntity>()
            .SetID(HKMakeFOURCC('F', 'X', 'E', 'T'), "Halak", "EffectEntity")
            .Inherits<Entity>()
            .Inherits<IUpdateable>();
    }
}
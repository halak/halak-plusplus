#include <Halak.Toolkit/PCH.h>
#include <Halak/EffectEntity.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

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
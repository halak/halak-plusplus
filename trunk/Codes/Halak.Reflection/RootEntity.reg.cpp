#include <Halak.Toolkit/PCH.h>
#include <Halak/RootEntity.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void RootEntity::__Startup__()
    {
        Class<RootEntity>()
            .SetID(HKMakeFOURCC('R', 'T', 'E', 'T'), "Halak", "RootEntity")
            .Inherits<Entity>();
    }
}
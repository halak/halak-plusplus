#include <Halak/RootEntity.h>
#include <Halak/Attributes.h>
#include <Halak/FOURCC.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void RootEntity::__Startup__()
    {
        Class<RootEntity>()
            .SetID(HKMakeFOURCC('R', 'T', 'E', 'T'), "Halak", "RootEntity")
            .Inherits<Entity>();
    }
}
#include <Halak.Toolkit/PCH.h>
#include <Halak/Entity.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void Entity::__Startup__()
    {
        Class<Entity>()
            .SetID(HKMakeFOURCC('E', 'N', 'T', 'Y'), "Halak", "Entity")
            .Inherits<ICloneable>()
            .Inherits<IDisposable>()
            .Add(new PropertyInfo(HKMakeFOURCC('N', 'A', 'M', 'E'), "Name", &GetName, &SetName));
    }
}
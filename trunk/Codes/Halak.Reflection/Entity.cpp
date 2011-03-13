#include <Halak/Entity.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

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
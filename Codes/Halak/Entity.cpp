#include <Halak/PCH.h>
#include <Halak/Entity.h>
#include <Halak/CloningContext.h>
#include <algorithm>

namespace Halak
{
    Entity::Entity()
    {
    }

    Entity::Entity(const String& name)
        : name(name)
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::Dispose()
    {
    }

    void Entity::SetName(const String& value)
    {
        if (name != value)
        {
            String old = name;
            name = value;

            OnNameChanged(old);
            nameChangedEvent.Emit(this, old);
        }
    }

    void Entity::OnNameChanged(const String& /*old*/)
    {
    }
}
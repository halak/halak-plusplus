#include <Halak/PCH.h>
#include <Halak/EntityWorld.h>
#include <Halak/Entity.h>
#include <algorithm>

namespace Halak
{
    EntityWorld::EntityWorld()
    {
    }

    EntityWorld::~EntityWorld()
    {
    }

    void EntityWorld::Dispose()
    {
    }

    void EntityWorld::Add(Entity* entity)
    {
        if (entity)
            entities.insert(entity);
    }

    bool EntityWorld::Remove(Entity* entity)
    {
        if (entity == false)
            return false;

        EntityCollection::iterator it = entities.find(entity);
        if (it != entities.end())
        {
            entities.erase(it);
            return true;
        }
        else
            return false;
    }

    void EntityWorld::Clear()
    {
        entities.clear();
    }

    void* EntityWorld::QueryClass(uint32 classID)
    {
        if (classID == IDisposable::ClassID)
            return static_cast<IDisposable*>(this);
        else
            return GameComponent::QueryClass(classID);
    }
}
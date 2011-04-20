#include <Halak/PCH.h>
#include <Halak/EntityWorld.h>
#include <Halak/Entity.h>

namespace Halak
{
    EntityWorld::EntityWorld()
    {
    }

    EntityWorld::~EntityWorld()
    {
    }

    void EntityWorld::Add(Entity* entity)
    {
        if (entity == nullptr)
            return;

        entities.push_back(entity);
    }

    bool EntityWorld::Remove(Entity* entity)
    {
        if (entity == nullptr)
            return;

    }

    void EntityWorld::Clear()
    {
        entities.clear();
    }
}
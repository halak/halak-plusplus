#include <Halak/EntityWorld.h>
#include <Halak/Entity.h>

namespace Halak
{
    EntityWorld::EntityWorld()
        : root(new Entity("ROOT"))
    {
    }

    EntityWorld::~EntityWorld()
    {
        root->Dispose();
        root.Reset();
    }

    EntityPtr EntityWorld::GetRoot() const
    {
        return root;
    }
}
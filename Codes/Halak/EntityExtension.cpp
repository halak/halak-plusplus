#include <Halak/EntityExtension.h>
#include <Halak/Assert.h>
#include <Halak/Entity.h>
#include <Halak/IPickable.h>

namespace Halak
{
    bool EntityExtension::Pick(EntityPtr target, PickingContext& context)
    {
        HKAssert(target);

        typedef Entity::EntityCollection EntityCollection;
        const EntityCollection& children = target->GetChildren();
        for (EntityCollection::const_iterator it = children.begin(); it != children.end(); it++)
        {
            EntityPtr item = (*it);

            if (IPickablePtr pickableEntity = dynamic_pointer_cast<IPickable>(item))
                pickableEntity->Pick(context);

            Pick(item, context);
        }

        return context.GetResults().empty() == false;
    }
}
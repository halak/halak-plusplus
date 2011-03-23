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

    Entity::Entity(const Entity& original, CloningContext& context)
        : ICloneable(context),
          name(original.name)
    {
        for (EntityCollection::const_iterator it = original.children.begin(); it != original.children.end(); it++)
        {
            children.push_back(context.Clone(*it));
        }
    }

    Entity::~Entity()
    {
    }

    Entity* Entity::Clone() const
    {
        return static_cast<Entity*>(ICloneable::Clone());
    }

    Entity* Entity::CloneWith(CloningContext& context) const
    {
        return new Entity(*this, context);
    }

    void Entity::Dispose()
    {
        EntityCollection temporaryChildren;
        temporaryChildren.swap(children);

        for (EntityCollection::iterator it = temporaryChildren.begin(); it != temporaryChildren.end(); it++)
        {
            (*it)->parent.reset();
            (*it)->Dispose();
        }

        if (parent.IsAlive())
        {
            parent.Lock()->RemoveChild(CastTo<Entity>());
            parent.reset();
        }
    }

    void Entity::AddChild(EntityPtr item)
    {
        EntityCollection::iterator it = std::find(children.begin(), children.end(), item);
        if (it == children.end())
        {
            if (item->parent.IsAlive())
                item->parent.Lock()->RemoveChild(item);

            children.push_back(item);
            item->parent = CastTo<Entity>();

            childAdded.Emit(this, item);
            OnChildAdded(item);
        }
    }

    void Entity::RemoveChild(EntityPtr item)
    {
        EntityCollection::iterator it = std::find(children.begin(), children.end(), item);
        if (it != children.end())
        {
            item->parent.reset();
            children.erase(it);

            childRemoved.Emit(this, item);
            OnChildRemoved(item);
        }
    }

    void Entity::SetName(const String& value)
    {
        if (name != value)
        {
            String old = name;
            name = value;

            OnNameChanged(old);
            nameChanged.Emit(this, old);
        }
    }

    void Entity::OnChildAdded(EntityPtr /*child*/)
    {
    }

    void Entity::OnChildRemoved(EntityPtr /*child*/)
    {
    }

    void Entity::OnNameChanged(const String& /*old*/)
    {
    }
}
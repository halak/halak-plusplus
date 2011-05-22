#include <Halak/PCH.h>
#include <Halak/Entity.h>
#include <Halak/CloningContext.h>
#include <Halak/SharedObject.h>
#include <algorithm>

namespace Halak
{
    struct ComponentPredicate
    {
        bool operator () (const Entity::Component& a, const Entity::Component& b) const
        {
            return a.Name < b.Name;
        }

        bool operator () (const String& name, const Entity::Component& b) const
        {
            return name < b.Name;
        }

        bool operator () (const Entity::Component& a, const String& name) const
        {
            return a.Name < name;
        }
    };
    
    Entity::Entity()
    {
    }

    Entity::Entity(const String& name)
        : name(name)
    {
    }

    Entity::Entity(const String& name, int componentCapacity)
        : name(name)
    {
        components.reserve(componentCapacity);
    }

    Entity::~Entity()
    {
    }

    void Entity::Dispose()
    {
    }

    const Entity::Component* Entity::Find(const String& name) const
    {
        ComponentCollection::const_iterator it = FindIterator(name);
        if (it != components.end())
            return &(*it);
        else
            return nullptr;
    }

    void Entity::SetName(const String& value)
    {
        if (name != value)
        {
            const String old = name;
            name = value;

            OnNameChanged(old);
        }
    }

    void Entity::SetComponents(const ComponentCollection& value)
    {
        components = value;
        std::sort(components.begin(), components.end(), ComponentPredicate());
    }

    void Entity::Insert(const Component& item)
    {
        ComponentCollection::iterator it = FindIterator(item.Name);
        if (it != components.end())
            (*it) = item;
        else
        {
            it = std::lower_bound(components.begin(), components.end(), item, ComponentPredicate());

            components.insert(it, item);
        }

        OnComponentChanged(item);
    }

    bool Entity::Remove(const String& name)
    {
        Entity::ComponentCollection::iterator it = FindIterator(name);
        if (it != components.end())
        {
            Component removedComponent = (*it);
            components.erase(it);
            OnComponentRemoved(removedComponent);
            return true;
        }
        else
            return false;
    }

    Entity::ComponentCollection::iterator Entity::FindIterator(const String& name)
    {
        ComponentCollection::iterator it = std::lower_bound(components.begin(), components.end(), name, ComponentPredicate());
        if (it != components.end() && (*it).Name == name)
            return it;
        else
            return components.end();
    }

    Entity::ComponentCollection::const_iterator Entity::FindIterator(const String& name) const
    {
        ComponentCollection::const_iterator it = std::lower_bound(components.begin(), components.end(), name, ComponentPredicate());
        if (it != components.end() && (*it).Name == name)
            return it;
        else
            return components.end();
    }

    void Entity::OnNameChanged(const String& /*old*/)
    {
    }

    void Entity::OnComponentChanged(const Component& /*item*/)
    {
    }

    void Entity::OnComponentRemoved(const Component& /*item*/)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity::Component::Component()
        : Name(String::Empty),
          Tag(String::Empty),
          Value(nullptr),
          Object(nullptr)
    {
    }

    Entity::Component::Component(const String& name, const String& tag, void* value)
        : Name(name),
          Tag(tag),
          Value(value),
          Object(nullptr)
    {
    }

    Entity::Component::Component(const String& name, const String& tag, SharedObject* value)
        : Name(name),
          Tag(tag),
          Value(static_cast<void*>(value)),
          Object(value)
    {
    }

    Entity::Component::Component(const Component& original)
        : Name(original.Name),
          Tag(original.Tag),
          Value(original.Value),
          Object(original.Object)
    {
    }

    Entity::Component& Entity::Component::operator = (const Component& right)
    {
        if (this == &right)
            return *this;

        Name = right.Name;
        Tag = right.Tag;
        Value = right.Value;
        Object = right.Object;
        return *this;
    }

    bool Entity::Component::operator == (const Component& right) const
    {
        return (this == &right) ||
               (Name == right.Name &&
                Tag == right.Tag &&
                Value == right.Value &&
                Object == right.Object);
    }
}
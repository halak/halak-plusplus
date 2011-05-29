#include <Halak/PCH.h>
#include <Halak/Entity.h>
#include <Halak/CloningContext.h>
#include <Halak/ObjectOperators.h>
#include <Halak/SharedObject.h>
#include <algorithm>

namespace Halak
{
    struct ComponentPredicate
    {
        inline bool operator () (const EntityComponent& a, const EntityComponent& b) const
        {
            return a.GetName() < b.GetName();
        }

        inline bool operator () (const String& name, const EntityComponent& b) const
        {
            return name < b.GetName();
        }

        inline bool operator () (const EntityComponent& a, const String& name) const
        {
            return a.GetName() < name;
        }
    };

    Entity::Entity()
    {
    }
    
    Entity::Entity(int numberOfIndexedComponents)
    {
        indexedComponents.resize(numberOfIndexedComponents);
    }

    Entity::Entity(const String& type)
        : type(type)
    {
    }

    Entity::Entity(const String& type, const String& name)
        : type(type),
          name(name)
    {
    }

    Entity::Entity(const String& type, const String& name, int numberOfIndexedComponents)
        : type(type),
          name(name)
    {
        indexedComponents.resize(numberOfIndexedComponents);
    }

    Entity::~Entity()
    {
        DestructAll(indexedComponents);
        DestructAll(components);
    }

    void Entity::Insert(const EntityComponent& item)
    {
        ComponentCollection::iterator it = FindIterator(item.GetName());
        if (it != components.end())
        {
            if ((*it) != item)
            {
                EntityComponent removedComponent = (*it);
                (*it) = item;

                if (removedComponent.GetOperator())
                    removedComponent.GetOperator()->Destruct(removedComponent.GetObject());

                OnComponentRemoved(removedComponent);
            }
        }
        else
        {
            it = std::lower_bound(components.begin(), components.end(), item, ComponentPredicate());

            components.insert(it, item);
        }

        OnComponentChanged(item);
    }

    bool Entity::Remove(const String& name)
    {
        ComponentCollection::iterator it = FindIterator(name); 
        if (it != components.end())
        {
            EntityComponent removedComponent = (*it);
            components.erase(it);

            if (removedComponent.GetOperator())
                removedComponent.GetOperator()->Destruct(removedComponent.GetObject());

            OnComponentRemoved(removedComponent);

            return true;
        }
        else
            return false;
    }

    void Entity::RemoveAll()
    {
        ComponentCollection removedComponents;
        removedComponents.swap(components);

        DestructAll(removedComponents);

        if (removedComponents.empty() == false)
            OnComponentsRemoved(removedComponents);
    }

    const EntityComponent* Entity::Find(const String& name) const
    {
        ComponentCollection::const_iterator it = FindIterator(name);
        if (it != components.end())
            return &(*it);
        else
            return nullptr;
    }

    void Entity::SetComponents(const ComponentCollection& value)
    {
        ComponentCollection removedComponents;
        removedComponents.swap(components);

        components = value;
        std::sort(components.begin(), components.end(), ComponentPredicate());

        if (removedComponents.empty() == false)
            OnComponentsRemoved(removedComponents);
    }

    Entity::ComponentCollection::iterator Entity::FindIterator(const String& name)
    {
        ComponentCollection::iterator it = std::lower_bound(components.begin(), components.end(), name, ComponentPredicate());
        if (it != components.end() && (*it).GetName() == name)
            return it;
        else
            return components.end();
    }

    Entity::ComponentCollection::const_iterator Entity::FindIterator(const String& name) const
    {
        ComponentCollection::const_iterator it = std::lower_bound(components.begin(), components.end(), name, ComponentPredicate());
        if (it != components.end() && (*it).GetName() == name)
            return it;
        else
            return components.end();
    }

    void Entity::OnNameChanged(const String& /*old*/)
    {
    }

    void Entity::OnComponentChanged(const EntityComponent& /*item*/)
    {
    }

    void Entity::OnComponentRemoved(const EntityComponent& /*item*/)
    {
    }

    void Entity::OnComponentsRemoved(const ComponentCollection& /*items*/)
    {
    }

    void Entity::DestructAll(ComponentCollection& components)
    {
        for (ComponentCollection::iterator it = components.begin(); it != components.end(); it++)
        {
            const EntityComponent& item = (*it);
            if (item.GetOperator())
                item.GetOperator()->Destruct(item.GetObject());
        }
    }
}
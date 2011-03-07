#pragma once
#ifndef __HALAK_ENTITY_INL__
#define __HALAK_ENTITY_INL__

    namespace Halak
    {
        const String& Entity::GetName() const
        {
            return name;
        }

        EntityPtr Entity::GetParent() const
        {
            return parent.lock();
        }

        const Entity::EntityCollection& Entity::GetChildren() const
        {
            return children;
        }

        Signal<Entity*, EntityPtr>& Entity::ChildAdded()
        {
            return childAdded;
        }

        Signal<Entity*, EntityPtr>& Entity::ChildRemoved()
        {
            return childRemoved;
        }

        Signal<Entity*, const String&>& Entity::NameChanged()
        {
            return nameChanged;
        }
    }

#endif
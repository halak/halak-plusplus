#pragma once
#ifndef __HALAK_ENTITY_H__
#define __HALAK_ENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/IDisposable.h>
#   include <Halak/Signal.h>
#   include <Halak/String.h>
#   include <list>

    namespace Halak
    {
        class Entity : public SharedObject, public IDisposable
        {
            public:
                typedef std::list<EntityPtr> EntityCollection;

            public:
                Entity();
                Entity(const String& name);
                ///^Entity(const Entity& original, CloningContext& context);
                virtual ~Entity();

                virtual Entity* Clone() const;
                virtual Entity* CloneWith(CloningContext& context) const;
                virtual void Dispose();

                void AddChild(EntityPtr item);
                void RemoveChild(EntityPtr item);

                inline EntityPtr GetParent() const;
                inline const EntityCollection& GetChildren() const;

                inline const String& GetName() const;
                void SetName(const String& value);

                inline Signal<Entity*, EntityPtr>& ChildAdded();
                inline Signal<Entity*, EntityPtr>& ChildRemoved();
                inline Signal<Entity*, const String&>& NameChanged();

            protected:
                virtual void OnChildAdded(EntityPtr child);
                virtual void OnChildRemoved(EntityPtr child);
                virtual void OnNameChanged(const String& old);

            private:
                String name;
                EntityWeakPtr parent;
                EntityCollection children;

                Signal<Entity*, EntityPtr> childAdded;
                Signal<Entity*, EntityPtr> childRemoved;
                Signal<Entity*, const String&> nameChanged;

            private:
                Entity(const Entity&);
                Entity& operator = (const Entity&);

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#   include <Halak/Entity.inl>

#endif
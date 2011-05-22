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
                struct Component
                {
                    String Name;
                    String Tag;
                    void* Value;
                    SharedObjectPtr Object;

                    Component();
                    Component(const String& name, const String& tag, void* value);
                    Component(const String& name, const String& tag, SharedObject* value);
                    Component(const Component& original);

                    Component& operator = (const Component& right);
                    bool operator == (const Component& right) const;
                    inline bool operator != (const Component& right) const;
                };
                typedef std::vector<Component> ComponentCollection;

            public:
                Entity();
                Entity(const String& name);
                Entity(const String& name, int componentCapacity);
                virtual ~Entity();

                virtual void Dispose();

                const Component* Find(const String& name) const;

                inline const String& GetName() const;
                void SetName(const String& value);

                inline const ComponentCollection& GetComponents() const;
                void SetComponents(const ComponentCollection& value);

            protected:
                void Insert(const Component& item);
                bool Remove(const String& name);

                ComponentCollection::iterator FindIterator(const String& name);
                ComponentCollection::const_iterator FindIterator(const String& name) const;

                virtual void OnNameChanged(const String& old);
                virtual void OnComponentChanged(const Component& item);
                virtual void OnComponentRemoved(const Component& item);

            private:
                String name;
                ComponentCollection components;

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
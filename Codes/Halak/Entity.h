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
                    SharedObjectPtr Object;
                    ICloneable*  CloneableInterface;
                    IDisposable* DisposableInterface;
                    IClassQueryable* QueryableInterface;
                };
                typedef std::list<Component*> ComponentCollection;

            public:
                Entity();
                Entity(const String& name);
                virtual ~Entity();

                virtual void Dispose();

                inline const String& GetName() const;
                void SetName(const String& value);

                inline Signal<Entity*, const String&>& NameChangedEvent();

            protected:
                virtual void OnNameChanged(const String& old);

            private:
                String name;
                ComponentCollection components;

                Signal<Entity*, const String&> nameChangedEvent;

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
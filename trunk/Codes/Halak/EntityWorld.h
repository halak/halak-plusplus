#pragma once
#ifndef __HALAK_ENTITYWORLD_H__
#define __HALAK_ENTITYWORLD_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IDisposable.h>
#   include <set>

    namespace Halak
    {
        class EntityWorld : public GameComponent, public IDisposable
        {
            HKClassFOURCC('E', 'N', 'T', 'W');
            public:
                typedef std::set<EntityPtr> EntityCollection;

            public:
                EntityWorld();
                virtual ~EntityWorld();
                
                virtual void Dispose();

                void Add(Entity* entity);
                bool Remove(Entity* entity);
                void Clear();

                inline EntityCollection& GetEntities() const;

                virtual void* QueryClass(uint32 classID);

            private:
                EntityCollection entities;
        };
    }

#endif
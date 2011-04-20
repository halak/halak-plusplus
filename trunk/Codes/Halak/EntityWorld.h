#pragma once
#ifndef __HALAK_ENTITYWORLD_H__
#define __HALAK_ENTITYWORLD_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <list>

    namespace Halak
    {
        class EntityWorld : public GameComponent
        {
            HKClassFOURCC('E', 'N', 'T', 'W');
            public:
                typedef std::list<EntityPtr> EntityCollection;

            public:
                EntityWorld();
                virtual ~EntityWorld();

                void Add(Entity* entity);
                bool Remove(Entity* entity);
                void Clear();

                inline EntityCollection& GetEntities() const;

            private:
                EntityCollection entities;
        };
    }

#endif
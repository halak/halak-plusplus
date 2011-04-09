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
                EntityWorld();

                EntityPtr GetRoot() const;

            protected:
                virtual ~EntityWorld();

            private:
                EntityPtr root;
        };
    }

#endif
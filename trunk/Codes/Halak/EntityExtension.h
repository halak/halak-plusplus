#pragma once
#ifndef __HALAK_ENTITY_EXTENSION_H__
#define __HALAK_ENTITY_EXTENSION_H__

#   include <Halak/FWD.h>
#   include <Halak/PickingContext.h>

    namespace Halak
    {
        class EntityExtension
        {
            public:
                static bool Pick(EntityPtr target, PickingContext& context);

            private:
                EntityExtension();
                EntityExtension(const EntityExtension&);
                EntityExtension& operator = (const EntityExtension&);
        };
    }

#endif
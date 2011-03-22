#pragma once
#ifndef __HALAL_PICKABLE_INTERFACE__
#define __HALAL_PICKABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IPickable
        {
            HKClassIDFOURCC('I', 'P', 'K', 'B');
            public:
                virtual ~IPickable() { }

                virtual bool Pick(PickingContext& context) = 0;
        };
    }

#endif
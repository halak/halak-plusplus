#pragma once
#ifndef __HALAK_UPDATEABLE_INTERFACE__
#define __HALAK_UPDATEABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IUpdateable
        {
            HKInterfaceFOURCC('I', 'U', 'D', 'T');
            public:
                virtual ~IUpdateable() { }

                virtual void Update(float dt, uint timestamp) = 0;
        };
    }

#endif
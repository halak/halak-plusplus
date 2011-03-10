#pragma once
#ifndef __HALAK_UPDATEABLE_INTERFACE__
#define __HALAK_UPDATEABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IUpdateable
        {
            public:
                static const uint ClassID = 0x00000001;

            public:
                virtual ~IUpdateable() { }

                virtual void Update(float dt, uint timestamp) = 0;
        };
    }

#endif
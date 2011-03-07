#pragma once
#ifndef __HALAK_CLOCK_H__
#define __HALAK_CLOCK_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class Clock
        {
            public:
                static float GetCurrent();
                static uint  GetCurrentMilliSeconds();
                static bool IsHighResolution();

            private:
                Clock();
                ~Clock();
        };
    }

#endif
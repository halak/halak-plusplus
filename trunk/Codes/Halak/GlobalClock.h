#pragma once
#ifndef __HALAK_GLOBALCLOCK_H__
#define __HALAK_GLOBALCLOCK_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class GlobalClock
        {
            public:
                static float GetCurrent();
                static uint  GetCurrentMilliSeconds();
                static bool IsHighResolution();

            private:
                GlobalClock();
                GlobalClock(const GlobalClock&);
                GlobalClock& operator = (const GlobalClock&);
                ~GlobalClock();
        };
    }

#endif
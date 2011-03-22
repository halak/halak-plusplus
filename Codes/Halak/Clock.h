#pragma once
#ifndef __HALAK_CLOCK_H__
#define __HALAK_CLOCK_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class Clock
        {
            HKThisIsStaticClass(Clock);
            public:
                static float GetCurrent();
                static uint  GetCurrentMilliSeconds();
                static bool IsHighResolution();
        };
    }

#endif
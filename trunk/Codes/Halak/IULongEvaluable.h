#pragma once
#ifndef __HALAK_ULONGEVALUABLE_INTERFACE__
#define __HALAK_ULONGEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IULongEvaluable
        {
            public:
                virtual ~IULongEvaluable() { }
                virtual ulong Evaluate() = 0;
        };
    }

#endif
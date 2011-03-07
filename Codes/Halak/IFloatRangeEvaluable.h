#pragma once
#ifndef __HALAK_FLOATRANGEEVALUABLE_INTERFACE__
#define __HALAK_FLOATRANGEEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Range.h>

    namespace Halak
    {
        class IFloatRangeEvaluable
        {
            public:
                virtual ~IFloatRangeEvaluable() { }
                virtual FloatRange Evaluate() = 0;
        };
    }

#endif
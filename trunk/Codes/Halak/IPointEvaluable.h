#pragma once
#ifndef __HALAK_POINTEVALUABLE_INTERFACE__
#define __HALAK_POINTEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        class IPointEvaluable
        {
            public:
                virtual ~IPointEvaluable() { }
                virtual Point Evaluate() = 0;
        };
    }

#endif
#pragma once
#ifndef __HALAK_FLOATEVALUABLE_INTERFACE__
#define __HALAK_FLOATEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IFloatEvaluable
        {
            public:
                virtual ~IFloatEvaluable() { }
                virtual float Evaluate() = 0;
        };
    }

#endif
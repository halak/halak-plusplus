#pragma once
#ifndef __HALAK_LONGEVALUABLE_INTERFACE__
#define __HALAK_LONGEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ILongEvaluable
        {
            public:
                virtual ~ILongEvaluable() { }
                virtual long Evaluate() = 0;
        };
    }

#endif
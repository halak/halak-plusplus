#pragma once
#ifndef __HALAK_SHORTEVALUABLE_INTERFACE__
#define __HALAK_SHORTEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IShortEvaluable
        {
            public:
                virtual ~IShortEvaluable() { }
                virtual short Evaluate() = 0;
        };
    }

#endif
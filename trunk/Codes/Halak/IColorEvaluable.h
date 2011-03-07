#pragma once
#ifndef __HALAK_COLOREVALUABLE_INTERFACE__
#define __HALAK_COLOREVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>

    namespace Halak
    {
        class IColorEvaluable
        {
            public:
                virtual ~IColorEvaluable() { }
                virtual Color Evaulate() = 0;
        };
    }

#endif
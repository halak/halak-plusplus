#pragma once
#ifndef __HALAK_RECTANGLEEVALUABLE_INTERFACE__
#define __HALAK_RECTANGLEEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IRectangleEvaluable
        {
            public:
                virtual ~IRectangleEvaluable() { }
                virtual Rectangle Evaluate() = 0;
        };
    }

#endif
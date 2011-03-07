#pragma once
#ifndef __HALAK_BOOLEVALUABLE_INTERFACE__
#define __HALAK_BOOLEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IBoolEvaluable
        {
            public:
                virtual ~IBoolEvaluable() { }
                virtual bool Evaulate() = 0;
        };
    }

#endif
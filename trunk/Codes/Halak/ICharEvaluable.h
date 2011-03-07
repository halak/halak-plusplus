#pragma once
#ifndef __HALAK_CHAREVALUABLE_INTERFACE__
#define __HALAK_CHAREVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ICharEvaluable
        {
            public:
                virtual ~ICharEvaluable() { }
                virtual char Evaulate() = 0;
        };
    }

#endif
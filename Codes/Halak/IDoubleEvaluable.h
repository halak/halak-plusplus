#pragma once
#ifndef __HALAK_DOUBLEEVALUABLE_INTERFACE__
#define __HALAK_DOUBLEEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IDoubleEvaluable
        {
            public:
                virtual ~IDoubleEvaluable() { }
                virtual double Evaulate() = 0;
        };
    }

#endif
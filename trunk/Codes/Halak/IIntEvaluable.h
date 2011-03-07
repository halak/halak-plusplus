#pragma once
#ifndef __HALAK_INTEVALUABLE_INTERFACE__
#define __HALAK_INTEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IIntEvaluable
        {
            public:
                virtual ~IIntEvaluable() { }
                virtual int Evaluate() = 0;
        };
    }

#endif
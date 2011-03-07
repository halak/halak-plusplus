#pragma once
#ifndef __HALAK_UCHAREVALUABLE_INTERFACE__
#define __HALAK_UCHAREVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IUCharEvaluable
        {
            public:
                virtual ~IUCharEvaluable() { }
                virtual uchar Evaluate() = 0;
        };
    }

#endif
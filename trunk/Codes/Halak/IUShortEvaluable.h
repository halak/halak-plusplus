#pragma once
#ifndef __HALAK_USHORTEVALUABLE_INTERFACE__
#define __HALAK_USHORTEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IUShortEvaluable
        {
            public:
                virtual ~IUShortEvaluable() { }
                virtual ushort Evaluate() = 0;
        };
    }

#endif
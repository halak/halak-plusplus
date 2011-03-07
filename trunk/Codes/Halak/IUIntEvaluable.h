#pragma once
#ifndef __HALAK_UINTEVALUABLE_INTERFACE__
#define __HALAK_UINTEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IUIntEvaluable
        {
            public:
                virtual ~IUIntEvaluable() { }
                virtual uint Evaluate() = 0;
        };
    }

#endif
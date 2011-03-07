#pragma once
#ifndef __HALAK_QUATERNIONEVALUABLE_INTERFACE__
#define __HALAK_QUATERNIONEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IQuaternionEvaluable
        {
            public:
                virtual ~IQuaternionEvaluable() { }
                virtual Quaternion Evaluate() = 0;
        };
    }

#endif
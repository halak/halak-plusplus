#pragma once
#ifndef __HALAK_VECTOR4EVALUABLE_INTERFACE__
#define __HALAK_VECTOR4EVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Vector4.h>

    namespace Halak
    {
        class IVector4Evaluable
        {
            public:
                virtual ~IVector4Evaluable() { }
                virtual Vector4 Evaluate() = 0;
        };
    }

#endif
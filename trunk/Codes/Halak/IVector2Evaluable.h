#pragma once
#ifndef __HALAK_VECTOR2EVALUABLE_INTERFACE__
#define __HALAK_VECTOR2EVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class IVector2Evaluable
        {
            public:
                virtual ~IVector2Evaluable() { }
                virtual Vector2 Evaluate() = 0;
        };
    }

#endif
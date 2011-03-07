#pragma once
#ifndef __HALAK_VECTOR3EVALUABLE_INTERFACE__
#define __HALAK_VECTOR3EVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        class IVector3Evaluable
        {
            public:
                virtual ~IVector3Evaluable() { }
                virtual Vector3 Evaluate() = 0;
        };
    }

#endif
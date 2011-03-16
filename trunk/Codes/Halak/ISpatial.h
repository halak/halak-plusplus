#pragma once
#ifndef __HALAK_SPATIAL_INTERFACE_H__
#define __HALAK_SPATIAL_INTERFACE_H__

#   include <Halak/FWD.h>
#   include <Halak/Quaternion.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        class ISpatial
        {
            HKDeclareClassFOURCC('I', 'S', 'P', 'L');
            public:
                virtual ~ISpatial() {}

                virtual Vector3 GetPosition() = 0;
                virtual void SetPosition(Vector3 value) = 0;

                virtual Quaternion GetRotation() = 0;
                virtual void SetRotation(Quaternion value) = 0;

                virtual float GetScale() = 0;
                virtual void  SetScale(float value) = 0;
        };
    }

#endif
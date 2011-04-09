#pragma once
#ifndef __HALAK_SPATIAL2D_INTERFACE_H__
#define __HALAK_SPATIAL2D_INTERFACE_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class ISpatial2D
        {
            HKInterfaceFOURCC('I', 'S', 'P', '2');
            public:
                virtual ~ISpatial2D() {}

                virtual Vector2 GetPosition() = 0;
                virtual void SetPosition(Vector2 value) = 0;

                virtual float GetRotation() = 0;
                virtual void  SetRotation(float value) = 0;

                virtual float GetScale() = 0;
                virtual void  SetScale(float value) = 0;
        };
    }

#endif
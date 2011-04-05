#pragma once
#ifndef __HALAK_AXISALIGNEDBOXSHAPE2D__
#define __HALAK_AXISALIGNEDBOXSHAPE2D__

#   include <Halak/Shape2D.h>

    namespace Halak
    {
        class AxisAlignedBoxShape2D : public Shape2D
        {
            public:
                AxisAlignedBoxShape2D();
                virtual ~AxisAlignedBoxShape2D();

                Vector2 GetMin() const;
                void    SetMin(Vector2 value);

                Vector2 GetMax() const;
                void    SetMax(Vector2 value);

                Vector2 GetScaledMin();
                Vector2 GetScaledMax();

                virtual bool Raycast(const Ray2D& ray, RaycastReport2D& outReport, IRaycastCallback2D* callback);
                virtual void AppendTo(std::list<Vector2>& vertices);

            private:
                void UpdateParameters();

            private:
                Vector2 min;
                Vector2 max;
                Vector2 scaledMin;
                Vector2 scaledMax;
                unsigned int revision;
        };
    }

#endif
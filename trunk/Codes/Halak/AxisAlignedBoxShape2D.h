#pragma once
#ifndef __TH_COLLISION2D_AXISALIGNEDRECTANGLESHAPE_H__
#define __TH_COLLISION2D_AXISALIGNEDRECTANGLESHAPE_H__

#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class AxisAlignedRectangleShape : public Shape
            {
                public:
                    AxisAlignedRectangleShape();
                    virtual ~AxisAlignedRectangleShape();

                    Vector2 GetMin() const;
                    void    SetMin(Vector2 value);

                    Vector2 GetMax() const;
                    void    SetMax(Vector2 value);

                    Vector2 GetScaledMin();
                    Vector2 GetScaledMax();

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    void UpdateParameters();

                private:
                    Vector2 min;
                    Vector2 max;
                    Vector2 scaledMin;
                    Vector2 scaledMax;
                    unsigned int revision;

                private:
                    AxisAlignedRectangleShape& operator = (const AxisAlignedRectangleShape&);
            };
        }
    }

#endif
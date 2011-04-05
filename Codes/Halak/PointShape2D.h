#pragma once
#ifndef __TH_COLLISION2D_POINTSHAPE_H__
#define __TH_COLLISION2D_POINTSHAPE_H__

#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class PointShape : public Shape
            {
                public:
                    PointShape();
                    virtual ~PointShape();

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    PointShape& operator = (const PointShape&);
            };
        }
    }

#endif
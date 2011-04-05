#pragma once
#ifndef __HALAK_POINTSHAPE2D__
#define __HALAK_POINTSHAPE2D__

#   include <Halak/FWD.h>
#   include <Halak/Shape2D.h>

    namespace Halak
    {
        class PointShape2D : public Shape2D
        {
            public:
                PointShape2D();
                virtual ~PointShape2D();

                virtual bool Raycast(const Ray2D& ray, RaycastReport2D& outReport, IRaycastCallback2D* callback);
                virtual void AppendTo(std::list<Vector2>& vertices);
        };
    }

#endif
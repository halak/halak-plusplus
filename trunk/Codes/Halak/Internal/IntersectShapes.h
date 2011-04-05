#pragma once
#ifndef __TH_COLLISION2D_ALGORITHM_INTERSECTSHAPES_H__
#define __TH_COLLISION2D_ALGORITHM_INTERSECTSHAPES_H__

#   include <TH/Collision2D/FWD.h>

    namespace TH
    {
        namespace Collision2D
        {
            namespace Algorithm
            {
                bool IntersectShapes(Shape* left, Shape* right);

                bool IntersectShapePointPoint(PointShape* left, PointShape* right);
                bool IntersectShapePointSegment(PointShape* left, SegmentShape* right);
                bool IntersectShapePointCircle(PointShape* left, CircleShape* right);
                bool IntersectShapePointAxisAlignedRectangle(PointShape* left, AxisAlignedRectangleShape* right);
                bool IntersectShapePointRectangle(PointShape* left, RectangleShape* right);
                bool IntersectShapePointUserShape(PointShape* left, UserShape* right);

                bool IntersectShapeSegmentSegment(SegmentShape* left, SegmentShape* right);
                bool IntersectShapeSegmentCircle(SegmentShape* left, CircleShape* right);
                bool IntersectShapeSegmentAxisAlignedRectangle(SegmentShape* left, AxisAlignedRectangleShape* right);
                bool IntersectShapeSegmentRectangle(SegmentShape* left, RectangleShape* right);
                bool IntersectShapeSegmentUserShape(SegmentShape* left, UserShape* right);

                bool IntersectShapeCircleCircle(CircleShape* left, CircleShape* right);
                bool IntersectShapeCircleAxisAlignedRectangle(CircleShape* left, AxisAlignedRectangleShape* right);
                bool IntersectShapeCircleRectangle(CircleShape* left, RectangleShape* right);
                bool IntersectShapeCircleUserShape(CircleShape* left, UserShape* right);

                bool IntersectShapeAxisAlignedRectangleAxisAlignedRectangle(AxisAlignedRectangleShape* left, AxisAlignedRectangleShape* right);
                bool IntersectShapeAxisAlignedRectangleRectangle(AxisAlignedRectangleShape* left, RectangleShape* right);
                bool IntersectShapeAxisAlignedRectangleUserShape(AxisAlignedRectangleShape* left, UserShape* right);

                bool IntersectShapeRectangleRectangle(RectangleShape* left, RectangleShape* right);
                bool IntersectShapeRectangleUserShape(RectangleShape* left, UserShape* right);

                bool IntersectShapeUserShapeUserShape(UserShape* left, UserShape* right);
            }
        }
    }

#endif
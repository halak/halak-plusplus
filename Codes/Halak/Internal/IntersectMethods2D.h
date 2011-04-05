#pragma once
#ifndef __HALAK_INTERSECTMETHODS2D_H__
#define __HALAK_INTERSECTMETHODS2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>
#   include <vector>

    namespace Halak
    {
        class IntersectMethods2D
        {
            HKThisIsStaticClass(IntersectMethods2D);
            public:
                // Point - AxisAlignedBox
                static float GetPointAxisAlignedBoxDistanceSquared(Vector2 p, Vector2 min, Vector2 max);

                // Point - Segment
                static bool PointSegment(Vector2 p, Vector2 a, Vector2 b);
                static float GetPointSegmentDistanceSquared(Vector2 p, Vector2 a, Vector2 b);

                // Point - Box
                static bool PointBox(Vector2 p, Vector2 origin, Vector2 axisX, Vector2 axisY, Vector2 extension);
                static Vector2 GetPointBoxClosestPoint(Vector2 p, Vector2 origin, Vector2 axisX, Vector2 axisY, Vector2 extension);

                // Point - Polygon
                static bool PointPolygon(Vector2 point, std::vector<Vector2> polygon);

                // Segment - Segment
                static bool SegmentSegment(Vector2 a, Vector2 b, Vector2 c, Vector2 d);
                static bool SegmentSegment(Vector2 a, Vector2 b, Vector2 c, Vector2 d, float& outResult);

                // Segment - AxisAlignedBox
                static bool SegmentAxisAlignedBox(Vector2 start, Vector2 end, Vector2 leftTop, Vector2 rightBottom);

                // AxisAlignedBox - AxisAlignedBox
                static bool AxisAlignedBoxAxisAlignedBox(Vector2 leftTop1, Vector2 rightBottom1, Vector2 leftTop2, Vector2 rightBottom2);

                // Box - Box
                static bool BoxBox(Vector2 center1, Vector2 orientation1, Vector2 extension1, Vector2 center2, Vector2 orientation2, Vector2 extension2);
        };
    }

#endif
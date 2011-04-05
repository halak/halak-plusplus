#pragma once
#ifndef __HALAK_RAYCASTMETHODS2D_H__
#define __HALAK_RAYCASTMETHODS2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class RaycastMethods2D
        {
            HKThisIsStaticClass(RaycastMethods2D);
            public:
                static bool Segment(Vector2 origin, Vector2 direction, float length, Vector2 start, Vector2 end, float& outDistance);
                static bool Sphere(Vector2 origin, Vector2 direction, Vector2 center, float radiusSquared, float& outDistance);
                static bool AxisAlignedBox(Vector2 origin, Vector2 direction, Vector2 leftTop, Vector2 rightBottom, float& outDistance, Vector2& outNormal);
                static bool Box(Vector2 origin, Vector2 direction, Vector2 center, Vector2 orientation, Vector2 extension, float& outDistance, Vector2& outNormal);
        };
    }

#endif
#pragma once
#ifndef __HALAK_RAY2D_H__
#define __HALAK_RAY2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        struct Ray2D
        {
            Vector2 Origin;
            Vector2 Direction;
            float   Length;

            Ray2D();
            Ray2D(Vector2 origin, Vector2 direction, float length);
            Ray2D(Vector2 start, Vector2 end);
            Ray2D(const Ray2D& original);

            Ray2D& operator = (const Ray2D& original);

            bool operator == (const Ray2D& right) const;
            bool operator != (const Ray2D& right) const;
        };
    }

#endif
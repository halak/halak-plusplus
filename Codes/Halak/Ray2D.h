#pragma once
#ifndef __HALAK_RAY2D_H__
#define __HALAK_RAY2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        struct Ray2D
        {
            HKDeclareStructFOURCC('R', 'A', 'Y', '2');

            Vector2 Origin;
            Vector2 Direction;
            float   Length;

            inline Ray2D();
            inline Ray2D(Vector2 origin, Vector2 direction, float length);
            inline Ray2D(Vector2 start, Vector2 end);
            inline Ray2D(const Ray2D& original);

            inline Ray2D& operator = (const Ray2D& original);

            inline bool operator == (const Ray2D& right) const;
            inline bool operator != (const Ray2D& right) const;
        };
    }

#   include <Halak/Ray2D.inl>

#endif
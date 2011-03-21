#pragma once
#ifndef __HALAK_RAY_H__
#define __HALAK_RAY_H__

#   include <Halak/Foundation.h>
#   include <Halak/Point.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        struct Ray;
        struct Matrix4;
        struct Rectangle;

        struct Ray
        {
            Vector3 Origin;
            Vector3 Direction;
            float   Length;

            inline Ray();
            inline Ray(Vector3 origin, Vector3 direction, float length);
            inline Ray(Vector3 start, Vector3 end);
            inline Ray(const Ray& original);

            inline Ray& operator = (const Ray& original);

            inline bool operator == (const Ray& right) const;
            inline bool operator != (const Ray& right) const;

            static Ray FromScreenSpace(Point point, const Matrix4& viewTransform, const Matrix4& projectionTransform, const Rectangle& viewport);

            static const Ray Empty;
        };
    }

#   include <Halak/Ray.inl>

#endif
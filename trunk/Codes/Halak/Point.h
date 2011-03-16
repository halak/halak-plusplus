#pragma once
#ifndef __HALAK_POINT_H__
#define __HALAK_POINT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        struct Point
        {
            HKDeclareStructFOURCC('P', 'O', 'N', 'T');

            int X;
            int Y;

            inline Point();
            inline Point(int x, int y);
            inline Point(const Point& original);

            inline Point& operator = (const Point& original);
            inline Point& operator += (const Point& right);
            inline Point& operator -= (const Point& right);

            inline Point operator + (const Point& right) const;
            inline Point operator - (const Point& right) const;

            inline bool operator == (const Point& right) const;
            inline bool operator != (const Point& right) const;

            static const Point Zero;
        };
    }

#   include <Halak/Point.inl>

#endif
#pragma once
#ifndef __HALAK_POINT_H__
#define __HALAK_POINT_H__

    namespace Halak
    {
        struct Point
        {
            int X;
            int Y;

            Point();
            Point(int x, int y);
            Point(const Point& original);

            Point& operator = (const Point& original);
            Point& operator += (const Point& right);
            Point& operator -= (const Point& right);

            Point operator + (const Point& right) const;
            Point operator - (const Point& right) const;

            bool operator == (const Point& right) const;
            bool operator != (const Point& right) const;

            static const Point Zero;
        };
    }

#endif
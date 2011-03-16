#pragma once
#ifndef __HALAK_RECTANGLE_H__
#define __HALAK_RECTANGLE_H__

#   include <Halak/Foundation.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        struct Rectangle
        {
            HKDeclareStructFOURCC('R', 'E', 'C', 'T');

            int X;
            int Y;
            int Width;
            int Height;

            inline Rectangle();
            inline Rectangle(int x, int y, int width, int height);
            inline Rectangle(Point leftTop, Point rightBottom);
            inline Rectangle(const Rectangle& original);

            inline int GetLeft() const;
            inline int GetTop() const;
            inline int GetRight() const;
            inline int GetBottom() const;
            inline Point GetCenter() const;

            inline void SetLeft(int value);
            inline void SetTop(int value);
            inline void SetRight(int value);
            inline void SetBottom(int value);

            inline bool Contains(Point p) const;

            inline bool IsEmpty() const;

            inline Rectangle& operator = (const Rectangle& original);
            
            inline bool operator == (const Rectangle& right) const;
            inline bool operator != (const Rectangle& right) const;

            static Rectangle Union(const Rectangle& a, const Rectangle& b);

            static const Rectangle Empty;
        };
    }

#   include <Halak/Rectangle.inl>

#endif
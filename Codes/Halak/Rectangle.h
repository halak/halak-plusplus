#pragma once
#ifndef __HALAK_RECTANGLE_H__
#define __HALAK_RECTANGLE_H__

#   include <Halak/Point.h>

    namespace Halak
    {
        struct Rectangle
        {
            int X;
            int Y;
            int Width;
            int Height;

            Rectangle();
            Rectangle(int x, int y, int width, int height);
            Rectangle(Point leftTop, Point rightBottom);
            Rectangle(const Rectangle& original);

            inline int GetLeft() const;
            inline int GetTop() const;
            inline int GetRight() const;
            inline int GetBottom() const;
            inline Point GetCenter() const;

            inline void SetLeft(int value);
            inline void SetTop(int value);
            inline void SetRight(int value);
            inline void SetBottom(int value);

            bool Contains(Point p) const;

            inline bool IsEmpty() const;

            Rectangle& operator = (const Rectangle& original);
            
            bool operator == (const Rectangle& right) const;
            bool operator != (const Rectangle& right) const;

            static Rectangle Union(const Rectangle& a, const Rectangle& b);

            static const Rectangle Empty;
        };
    }

#   include <Halak/Rectangle.inl>

#endif
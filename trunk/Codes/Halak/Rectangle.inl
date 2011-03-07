#pragma once
#ifndef __HALAK_RECTANGLE_INL__
#define __HALAK_RECTANGLE_INL__

    namespace Halak
    {
        int Rectangle::GetLeft() const
        {
            return X;
        }

        int Rectangle::GetTop() const
        {
            return Y;
        }

        int Rectangle::GetRight() const
        {
            return X + Width;
        }

        int Rectangle::GetBottom() const
        {
            return Y + Height;
        }

        Point Rectangle::GetCenter() const
        {
            return Point(X + Width / 2, Y + Height / 2);
        }

        void Rectangle::SetLeft(int value)
        {
            const int right = GetRight();

            X = value;
            Width = right - X;
        }

        void Rectangle::SetTop(int value)
        {
            const int bottom = GetBottom();

            Y = value;
            Height = bottom - Y;
        }

        void Rectangle::SetRight(int value)
        {
            Width = value - X;
        }

        void Rectangle::SetBottom(int value)
        {
            Height = value - Y;
        }

        bool Rectangle::IsEmpty() const
        {
            return Width == 0 || Height == 0;
        }
    }

#endif
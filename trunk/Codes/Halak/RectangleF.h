#pragma once
#ifndef __HALAK_RECTANGLEF_H__
#define __HALAK_RECTANGLEF_H__

#   include <Halak/Foundation.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        struct RectangleF
        {
            float X;
            float Y;
            float Width;
            float Height;

            inline RectangleF();
            inline RectangleF(float x, float y, float width, float height);
            inline RectangleF(Vector2 leftTop, Vector2 rightBottom);
            inline RectangleF(const RectangleF& original);

            inline float GetLeft() const;
            inline float GetTop() const;
            inline float GetRight() const;
            inline float GetBottom() const;
            inline Vector2 GetCenter() const;

            inline void SetLeft(float value);
            inline void SetTop(float value);
            inline void SetRight(float value);
            inline void SetBottom(float value);

            inline bool Contains(Vector2 p) const;

            inline bool IsEmpty() const;

            inline RectangleF& operator = (const RectangleF& original);
            
            inline bool operator == (const RectangleF& right) const;
            inline bool operator != (const RectangleF& right) const;

            static RectangleF Intersect(const RectangleF& a, const RectangleF& b);
            static RectangleF Union(const RectangleF& a, const RectangleF& b);

            static const RectangleF Empty;
        };
    }

#   include <Halak/RectangleF.inl>

#endif
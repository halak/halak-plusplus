#pragma once
#ifndef __HALAK_COLOR_H__
#define __HALAK_COLOR_H__

#   include <Halak/Foundation.h>
#   include <Halak/Vector3.h>
#   include <Halak/Vector4.h>

    namespace Halak
    {
        struct Color
        {
            byte A;
            byte R;
            byte G;
            byte B;

            inline Color();
            inline Color(int r, int g, int b);
            inline Color(int r, int g, int b, int a);
            inline Color(unsigned long argb);
            inline explicit Color(Vector3 rgb);
            inline explicit Color(Vector4 rgba);
            inline Color(const Color& original);

            inline Vector3 ToVector3() const;
            inline Vector4 ToVector4() const;
            inline unsigned long ToRGBA() const;
            inline unsigned long ToARGB() const;

            inline Color& operator = (const Color& original);
            inline Color& operator += (Color right);
            inline Color& operator -= (Color right);
            inline Color& operator *= (Color right);
            inline Color& operator *= (float right);
            inline Color& operator /= (Color right);
            inline Color& operator /= (float right);

            inline Color operator + (Color right) const;
            inline Color operator - (Color right) const;
            inline Color operator * (Color right) const;
            inline Color operator * (float right) const;
            inline Color operator / (Color right) const;
            inline Color operator / (float right) const;

            inline bool operator == (Color right) const;
            inline bool operator != (Color right) const;

            private:
                static inline byte Add(byte a, byte b);
                static inline byte Subtract(byte a, byte b);
                static inline byte Clamp(int value);
                static inline byte Clamp(float value);
        };
    }

#   include <Halak/Color.inl>
   
#endif
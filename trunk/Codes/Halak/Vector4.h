#pragma once
#ifndef __HALAK_VECTOR4_H__
#define __HALAK_VECTOR4_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        struct Vector4
        {
            HKDeclareStructFOURCC('V', 'E', 'C', '4');

            float X;
            float Y;
            float Z;
            float W;

            Vector4();
            Vector4(float x, float y, float z);
            Vector4(float x, float y, float z, float w);
            Vector4(const Vector3& original, float w);
            Vector4(const Vector4& original);

            inline Vector4  operator + () const;
            inline Vector4  operator - () const;

            inline Vector4& operator = (const Vector4& original);
            inline Vector4& operator += (const Vector4& right);
            inline Vector4& operator -= (const Vector4& right);
            inline Vector4& operator *= (float right);
            inline Vector4& operator /= (float right);
            inline Vector4  operator + (const Vector4& right) const;
            inline Vector4  operator - (const Vector4& right) const;
            inline Vector4  operator * (float right) const;
            inline Vector4  operator / (float right) const;
            
            inline bool operator == (const Vector4& right) const;
            inline bool operator != (const Vector4& right) const;

            inline friend Vector4 operator * (float left, const Vector4& right);

            static const Vector4 Zero;
            static const Vector4 UnitX;
            static const Vector4 UnitY;
            static const Vector4 UnitZ;
            static const Vector4 UnitW;
            static const Vector4 One;
        };
    }

#   include <Halak/Vector4.inl>

#endif
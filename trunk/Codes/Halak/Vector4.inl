#pragma once
#ifndef __HALAK_VECTOR4_INL__
#define __HALAK_VECTOR4_INL__

    namespace Halak
    {
        Vector4 Vector4::operator + () const
        {
            return Vector4(+X, +Y, +Z, +W);
        }

        Vector4 Vector4::operator - () const
        {
            return Vector4(-X, -Y, -Z, -W);
        }

        Vector4& Vector4::operator = (const Vector4& original)
        {
            X = original.X;
            Y = original.Y;
            Z = original.Z;
            W = original.W;
            return *this;
        }

        Vector4& Vector4::operator += (const Vector4& right)
        {
            X += right.X;
            Y += right.Y;
            Z += right.Z;
            W += right.W;
            return *this;
        }

        Vector4& Vector4::operator -= (const Vector4& right)
        {
            X -= right.X;
            Y -= right.Y;
            Z -= right.Z;
            W -= right.W;
            return *this;
        }

        Vector4& Vector4::operator *= (float right)
        {
            X *= right;
            Y *= right;
            Z *= right;
            W *= right;
            return *this;
        }

        Vector4& Vector4::operator /= (float right)
        {
            X /= right;
            Y /= right;
            Z /= right;
            W /= right;
            return *this;
        }

        Vector4 Vector4::operator + (const Vector4& right) const
        {
            return Vector4(X + right.X, Y + right.Y, Z + right.Z, W + right.W);
        }

        Vector4 Vector4::operator - (const Vector4& right) const
        {
            return Vector4(X - right.X, Y - right.Y, Z - right.Z, W - right.W);
        }

        Vector4 Vector4::operator * (float right) const
        {
            return Vector4(X * right, Y * right, Z * right, W * right);
        }

        Vector4 Vector4::operator / (float right) const
        {
            return Vector4(X / right, Y / right, Z / right, W / right);
        }

        bool Vector4::operator == (const Vector4& right) const
        {
            return X == right.X && Y == right.Y && Z == right.Z && W == right.W;
        }

        bool Vector4::operator != (const Vector4& right) const
        {
            return !operator == (right);
        }

        Vector4 operator * (float left, const Vector4& right)
        {
            return Vector4(left * right.X, left * right.Y, left * right.Z, left * right.W);
        }
    }

#endif
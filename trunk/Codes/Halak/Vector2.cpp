#include <Halak/PCH.h>
#include <Halak/Vector2.h>
#include <Halak/Math.h>
#include <Halak/NumericLimits.h>

namespace Halak
{
    float Vector2::Normalize()
    {
        // 크기가 1이면 Normalize를 수행하지 않습니다.
        if (Math::Equals(X * X + Y * Y, 1.0f))
            return 1.0f;

        const float length = GetLength();
        
        X /= length;
        Y /= length;
        
        return length;
    }

    void Vector2::Rotate(float rotation)
    {
        Rotate(Math::Sin(rotation), Math::Cos(rotation));
    }

    void Vector2::Rotate(float sin, float cos)
    {
        const Vector2 v = Vector2(X, Y);
        X = cos * v.X - sin * v.Y;
        Y = sin * v.X + cos * v.Y;
    }

    float Vector2::GetLength() const
    {
        return Math::Sqrt((X * X) + (Y * Y));
    }

    float Vector2::GetLengthSquared() const
    {
        return (X * X) + (Y * Y);
    }

    float Vector2::GetDistance(Vector2 a, Vector2 b)
    {
        return Math::Sqrt(GetDistanceSquared(a, b));
    }

    float Vector2::GetDistanceSquared(Vector2 a, Vector2 b)
    {
        return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y);
    }

    bool Vector2::IsCollinear(Vector2 a, Vector2 b, Vector2 c)
    {
        const float dx1 = b.X - a.X;
        const float dy1 = b.Y - a.Y;
        const float dx2 = c.X - a.X;
        const float dy2 = c.Y - a.Y;

        if (Math::Equals(dx1, 0.0f) == false && Math::Equals(dx2, 0.0f) == false)
            return Math::Equals(dy1 / dx1, dy2 / dx2);
        else
            return Math::Equals(dx1, dx2);
    }

    const Vector2 Vector2::Zero  = Vector2(0.0f, 0.0f);
    const Vector2 Vector2::UnitX = Vector2(1.0f, 0.0f);
    const Vector2 Vector2::UnitY = Vector2(0.0f, 1.0f);
    const Vector2 Vector2::One   = Vector2(1.0f, 1.0f);
    const Vector2 Vector2::Minimum = Vector2(NumericLimits::MinFloat, NumericLimits::MinFloat);
    const Vector2 Vector2::Maximum = Vector2(NumericLimits::MaxFloat, NumericLimits::MaxFloat);
}
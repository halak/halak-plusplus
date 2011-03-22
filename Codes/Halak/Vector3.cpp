#include <Halak/PCH.h>
#include <Halak/Vector3.h>
#include <Halak/Math.h>
#include <Halak/NumericLimits.h>

namespace Halak
{
    float Vector3::Normalize()
    {
        // 크기가 1이면 Normalize를 수행하지 않습니다.
        if (Math::Equals(X * X + Y * Y + Z * Z, 1.0f))
            return 1.0f;

        const float length = GetLength();
        
        X /= length;
        Y /= length;
        Z /= length;
        
        return length;
    }

    float Vector3::GetLength() const
    {
        return Math::Sqrt((X * X) + (Y * Y) + (Z * Z));
    }

    float Vector3::GetDistance(Vector3 a, Vector3 b)
    {
        return Math::Sqrt(GetDistanceSquared(a, b));
    }

    float Vector3::GetDistanceSquared(Vector3 a, Vector3 b)
    {
        return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y) + (b.Z - a.Z) * (b.Y - a.Z);
    }

    const Vector3 Vector3::Zero  = Vector3(0.0f, 0.0f, 0.0f);
    const Vector3 Vector3::UnitX = Vector3(1.0f, 0.0f, 0.0f);
    const Vector3 Vector3::UnitY = Vector3(0.0f, 1.0f, 0.0f);
    const Vector3 Vector3::UnitZ = Vector3(0.0f, 0.0f, 1.0f);
    const Vector3 Vector3::One   = Vector3(1.0f, 1.0f, 1.0f);
    const Vector3 Vector3::Minimum = Vector3(NumericLimits::MinFloat, NumericLimits::MinFloat, NumericLimits::MinFloat);
    const Vector3 Vector3::Maximum = Vector3(NumericLimits::MaxFloat, NumericLimits::MaxFloat, NumericLimits::MaxFloat);
}
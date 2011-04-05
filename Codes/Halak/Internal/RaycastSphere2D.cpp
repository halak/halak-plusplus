#include <Halak/PCH.h>
#include <Halak/Internal/RaycastMethods2D.h>
#include <Halak/Math.h>

namespace Halak
{
    bool RaycastMethods2D::Sphere(Vector2 origin, Vector2 direction, Vector2 center, float radiusSquared, float& outDistance)
    {
        const Vector2 m = origin - center;
        const float b = m.Dot(direction);
        const float c = m.Dot(m) - radiusSquared;

        if (c > 0.0f && b > 0.0f)
            return false;

        const float discriminant = (b * b) - c;
        if (discriminant >= 0.0f)
        {
            outDistance = std::max((-b) - static_cast<float>(Math::Sqrt(discriminant)), 0.0f);
            return true;
        }
        else
            return false;
    }
}
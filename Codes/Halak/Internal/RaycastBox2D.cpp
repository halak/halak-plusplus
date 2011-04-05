#include <Halak/PCH.h>
#include <Halak/Internal/RaycastMethods2D.h>
#include <Halak/Math.h>

namespace Halak
{
    bool RaycastMethods2D::Box(Vector2 origin, Vector2 direction, Vector2 center, Vector2 orientation, Vector2 extension, float& outDistance, Vector2& outNormal)
    {
        const float dot = orientation.Dot(Vector2::UnitX);
        float rotation = (float)Math::Acos(dot);
        if (orientation.Y > 0.0f)
            rotation = -rotation;

        const float sin = (float)Math::Sin(rotation);
        const float cos = (float)dot; // == Math.Cos(rotation)

        origin -= center;
        origin.Rotate(sin, cos);
        origin += center;
        direction.Rotate(sin, cos);

        const Vector2 leftTop = center - extension;
        const Vector2 rightBottom = center + extension;

        if (AxisAlignedBox(origin, direction, leftTop, rightBottom, outDistance, outNormal))
        {
            outNormal.Rotate(-sin, cos); // == normal.Rotate(-rotation)
            return true;
        }
        else
            return false;
    }
}
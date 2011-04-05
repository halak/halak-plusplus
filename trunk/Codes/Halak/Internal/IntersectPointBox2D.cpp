#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            bool IntersectPointRectangle(Vector2 p, Vector2 origin, Vector2 axisX, Vector2 axisY, Vector2 extension)
            {
                return Math::Equals(p, GetPointRectangleClosestPoint(p, origin, axisX, axisY, extension));
            }

            Vector2 GetPointRectangleClosestPoint(Vector2 p, Vector2 origin, Vector2 axisX, Vector2 axisY, Vector2 extension)
            {
                const Vector2 d = p - origin;
                return origin + (axisX * Math::Clamp(d.Dot(axisX), -extension.X, +extension.X)) + (axisY * Math::Clamp(d.Dot(axisY), -extension.Y, +extension.Y));
            }
        }
    }
}
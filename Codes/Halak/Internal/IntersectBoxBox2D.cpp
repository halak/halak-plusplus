#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            bool IntersectRectangleRectangle(Vector2 center1, Vector2 orientation1, Vector2 extension1, Vector2 center2, Vector2 orientation2, Vector2 extension2)
            {
                const Vector2 up1 = Vector2(+orientation1.Y, -orientation1.X);
                const Vector2 up2 = Vector2(+orientation2.Y, -orientation2.X);

                const float R11 = orientation1.Dot(orientation2);
                const float R12 = orientation1.Dot(up2);
                const float R21 = up1.Dot(orientation2);
                const float R22 = up1.Dot(up2);

                const Vector2 center1ToCenter2 = center2 - center1;
                const Vector2 t = Vector2(center1ToCenter2.Dot(orientation1), center1ToCenter2.Dot(up1));

                const float A11 = Math::Abs(R11) + 0.0001f;
                const float A12 = Math::Abs(R12) + 0.0001f;
                const float A21 = Math::Abs(R21) + 0.0001f;
                const float A22 = Math::Abs(R22) + 0.0001f;

                float r1 = 0.0f;
                float r2 = 0.0f;

                r1 = extension1.X;
                r2 = extension2.X * A11 + extension2.Y * A12;
                if (Math::Abs(t.X) > r1 + r2)
                    return false;
                r1 = extension1.Y;
                r2 = extension2.X * A21 + extension2.Y * A22;
                if (Math::Abs(t.Y) > r1 + r2)
                    return false;

                r1 = extension1.X * A11 + extension1.Y * A21;
                r2 = extension2.X;
                if (Math::Abs(t.X * R11 + t.Y * R21) > r1 + r2)
                    return false;
                r1 = extension1.X * A12 + extension1.Y * A22;
                r2 = extension2.Y;
                if (Math::Abs(t.X * R12 + t.Y * R22) > r1 + r2)
                    return false;

                return true;
            }
        }
    }
}
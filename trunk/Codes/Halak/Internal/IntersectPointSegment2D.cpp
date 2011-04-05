#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            bool IntersectPointSegment(Vector2 p, Vector2 a, Vector2 b)
            {
                return GetPointSegmentDistanceSquared(p, a, b) < 0.01f; // ±Ù»ç °ª
            }

            float GetPointSegmentDistanceSquared(Vector2 p, Vector2 a, Vector2 b)
            {
                const Vector2 ab = b - a;
                const Vector2 ap = p - a;
                const Vector2 bp = p - b;
                const float e = ab.Dot(ap);

                if (e > 0.0f)
                {
                    const float f = ab.Dot(ab);
                    if (e >= f)
                        return bp.Dot(bp);
                    else
                        return ap.Dot(ap) - e * e / f;
                }
                else
                    return ap.Dot(ap);
            }
        }
    }
}
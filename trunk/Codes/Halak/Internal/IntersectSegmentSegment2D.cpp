#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>

namespace Halak
{
    static float Signed2DTriArea(Vector2 a, Vector2 b, Vector2 c)
    {
        return (a.X - c.X) * (b.Y - c.Y) - (a.Y - c.Y) * (b.X - c.X);
    }

    bool IntersectMethods2D::SegmentSegment(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
    {
        float t = 0.0f;
        return SegmentSegment(a, b, c, d, t);
    }

    bool IntersectMethods2D::SegmentSegment(Vector2 a, Vector2 b, Vector2 c, Vector2 d, float& outResult)
    {
        float a1 = Signed2DTriArea(a, b, d);
        float a2 = Signed2DTriArea(a, b, c);
        if (a1 * a2 < 0.0f)
        {
            float a3 = Signed2DTriArea(c, d, a);
            float a4 = a3 + a2 - a1;
            if (a3 * a4 < 0.0f)
            {
                outResult = a3 / (a3 - a4);
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}
#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            bool IntersectSegmentAxisAlignedRectangle(Vector2 start, Vector2 end, Vector2 leftTop, Vector2 rightBottom)
            {
                const Vector2 c = (leftTop + rightBottom) * 0.5f;
                const Vector2 e = rightBottom - c;
                Vector2 m = (start + end) * 0.5f;
                const Vector2 d = end - m;

                m.X -= c.X;
                m.Y -= c.Y;

                float adx = Math::Abs(d.X);
                if (Math::Abs(m.X) > e.X + adx)
                    return false;

                float ady = Math::Abs(d.Y);
                if (Math::Abs(m.Y) > e.Y + ady)
                    return false;

                adx += 0.0001f;
                ady += 0.0001f;

                return Math::Abs(m.X * d.Y - m.Y * d.X) <= e.X * ady + e.Y * adx;
            }
        }
    }
}
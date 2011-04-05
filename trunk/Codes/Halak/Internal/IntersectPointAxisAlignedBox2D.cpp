#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Assert.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            float GetPointAxisAlignedRectangleDistanceSquared(Vector2 p, Vector2 min, Vector2 max)
            {
                float result = 0.0f;

                HKAssert(!((p.X < min.X && p.X > max.X) || (p.Y < min.Y && p.Y > max.Y)));

                if (p.X < min.X)
                    result += (min.X - p.X) * (min.X - p.X);
                else if (p.X > max.X)
                    result += (p.X - max.X) * (p.X - max.X);
                if (p.Y < min.Y)
                    result += (min.Y - p.Y) * (min.Y - p.Y);
                else if (p.Y > max.Y)
                    result += (p.Y - max.Y) * (p.Y - max.Y);

                return result;
            }
        }
    }
}
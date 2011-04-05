#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>

namespace Halak
{
    bool IntersectAxisAlignedRectangleAxisAlignedRectangle(Vector2 leftTop1, Vector2 rightBottom1, Vector2 leftTop2, Vector2 rightBottom2)
    {
        if (rightBottom1.X < leftTop2.X || leftTop1.X > rightBottom2.X)
            return false;
        if (rightBottom1.Y < leftTop2.Y || leftTop1.Y > rightBottom2.Y)
            return false;

        return true;
    }
}
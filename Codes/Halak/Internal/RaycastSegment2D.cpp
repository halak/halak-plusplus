#include <Halak/PCH.h>
#include <Halak/Internal/RaycastMethods2D.h>
#include <Halak/Internal/IntersectMethods2D.h>
#include <Halak/Math.h>

namespace Halak
{
    bool RaycastMethods2D::Segment(Vector2 origin, Vector2 direction, float length, Vector2 start, Vector2 end, float& outDistance)
    {
        float t = 0.0f;
        if (IntersectMethods2D::SegmentSegment(origin, origin + direction * length, start, end, t))
        {
            outDistance = t * length;
            return true;
        }
        else
            return false;
    }
}
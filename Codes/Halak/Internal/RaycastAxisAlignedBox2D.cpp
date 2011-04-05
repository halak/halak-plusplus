#include <Halak/PCH.h>
#include <Halak/Internal/RaycastMethods2D.h>
#include <Halak/Math.h>
#include <limits>

namespace Halak
{
    bool RaycastMethods2D::AxisAlignedBox(Vector2 origin, Vector2 direction, Vector2 leftTop, Vector2 rightBottom, float& outDistance, Vector2& outNormal)
    {
        float tMin = 0.0f;
        float tMax = std::numeric_limits<float>::max();

        if (Math::Abs(direction.X) < 0.00001f)
        {
            if (origin.X < leftTop.X || rightBottom.X < origin.X)
                return false;
        }
        else
        {
            float ood = 1.0f / direction.X;
            float t1 = (leftTop.X - origin.X) * ood;
            float t2 = (rightBottom.X - origin.X) * ood;

            if (t1 <= t2)
            {
                if (tMin < t1)
                {
                    tMin = t1;
                    outNormal.X = -1.0f;
                    outNormal.Y = +0.0f;
                }
                tMax = std::min(tMax, t2);
            }
            else
            {
                if (tMin < t2)
                {
                    tMin = t2;
                    outNormal.X = +1.0f;
                    outNormal.Y = +0.0f;
                }
                tMax = std::min(tMax, t1);
            }

            if (tMin > tMax)
                return false;
        }

        if (Math::Abs(direction.Y) < 0.00001f)
        {
            if (origin.Y < leftTop.Y || rightBottom.Y < origin.Y)
                return false;
        }
        else
        {
            float ood = 1.0f / direction.Y;
            float t1 = (leftTop.Y - origin.Y) * ood;
            float t2 = (rightBottom.Y - origin.Y) * ood;

            if (t1 <= t2)
            {
                if (tMin < t1)
                {
                    tMin = t1;
                    outNormal.X = +0.0f;
                    outNormal.Y = -1.0f;
                }
                tMax = std::min(tMax, t2);
            }
            else
            {
                if (tMin < t2)
                {
                    tMin = t2;
                    outNormal.X = +0.0f;
                    outNormal.Y = +1.0f;
                }
                tMax = std::min(tMax, t1);
            }

            if (tMin > tMax)
                return false;
        }

        outDistance = tMin;
        return true;
    }
}
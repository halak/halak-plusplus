#include <Halak/PCH.h>
#include <Halak/Internal/IntersectMethods2D.h>

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            bool IntersectPointPolygon(Vector2 point, std::vector<Vector2> polygon)
            {
                bool result = false;

                for (std::vector<Vector2>::size_type i = 0, k = polygon.size() - 1; i < polygon.size(); k = i++)
                {
                    if (((polygon[i].Y > point.Y) != (polygon[k].Y > point.Y)) &&
                        (point.X < (polygon[k].X - polygon[i].X) * (point.Y - polygon[i].Y) / (polygon[k].Y - polygon[i].Y) + polygon[i].X))
                    {
                        result = !result;
                    }
                }

                return result;
            }
        }
    }
}
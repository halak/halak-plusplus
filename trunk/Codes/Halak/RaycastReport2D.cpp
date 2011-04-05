#include <TH/Collision2D/RaycastReport.h>

namespace TH
{
    namespace Collision2D
    {
        RaycastReport::RaycastReport()
            : ImpactShape(0),
              ImpactPoint(Vector2::Zero),
              ImpactNormal(Vector2::Zero),
              ImpactDistance(0.0f)
        {
        }

        RaycastReport::RaycastReport(Shape* shape, const Vector2& point, const Vector2& normal, float distance)
            : ImpactShape(shape),
              ImpactPoint(point),
              ImpactNormal(normal),
              ImpactDistance(distance)
        {
        }

        RaycastReport::RaycastReport(const RaycastReport& original)
            : ImpactShape(original.ImpactShape),
              ImpactPoint(original.ImpactPoint),
              ImpactNormal(original.ImpactNormal),
              ImpactDistance(original.ImpactDistance)
        {
        }

        RaycastReport& RaycastReport::operator = (const RaycastReport& original)
        {
            ImpactShape = original.ImpactShape;
            ImpactPoint = original.ImpactPoint;
            ImpactNormal = original.ImpactNormal;
            ImpactDistance = original.ImpactDistance;
            return *this;
        }

        bool RaycastReport::operator == (const RaycastReport& right) const
        {
            return (ImpactShape == right.ImpactShape &&
                    ImpactPoint == right.ImpactPoint &&
                    ImpactNormal == right.ImpactNormal &&
                    ImpactDistance == right.ImpactDistance);
        }

        bool RaycastReport::operator != (const RaycastReport& right) const
        {
            return !operator == (right);
        }
    }
}
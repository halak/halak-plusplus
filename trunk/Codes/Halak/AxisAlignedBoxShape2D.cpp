#include <TH/Collision2D/AxisAlignedRectangleShape.h>
#include <TH/Collision2D/RaycastReport.h>
#include <TH/Collision2D/Algorithm/Raycast.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        AxisAlignedRectangleShape::AxisAlignedRectangleShape()
            : Shape(ShapeType::AxisAlignedRectangle),
              min(Vector2::Zero),
              max(Vector2::Zero),
              scaledMin(Vector2::Zero),
              scaledMax(Vector2::Zero),
              revision(0)
        {
        }

        AxisAlignedRectangleShape::~AxisAlignedRectangleShape()
        {
        }

        Vector2 AxisAlignedRectangleShape::GetMin() const
        {
            return min;
        }

        void AxisAlignedRectangleShape::SetMin(Vector2 value)
        {
            if (GetMin() != value)
            {
                min = value;
                revision = 0;
            }
        }

        Vector2 AxisAlignedRectangleShape::GetMax() const
        {
            return max;
        }

        void AxisAlignedRectangleShape::SetMax(Vector2 value)
        {
            if (GetMax() != value)
            {
                max = value;
                revision = 0;
            }
        }

        Vector2 AxisAlignedRectangleShape::GetScaledMin()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return scaledMin;
        }

        Vector2 AxisAlignedRectangleShape::GetScaledMax()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return scaledMax;
        }

        void AxisAlignedRectangleShape::UpdateParameters()
        {
            revision  = GetSpatialRevision();
            scaledMin = GetMin() * GetScale();
            scaledMax = GetMax() * GetScale();
        }

        bool AxisAlignedRectangleShape::Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback)
        {
            float outDistance = 0.0f;
            Vector2 outNormal = Vector2::Zero;
            if (Algorithm::RaycastAxisAlignedRectangle(ray.Origin, ray.Direction, GetScaledMin(), GetScaledMax(), outDistance, outNormal) && outDistance <= ray.Length)
            {
                if (callback == nullptr || callback->OnHit(distance * distance))
                {
                    outReport.ImpactShape = this;
                    outReport.ImpactPoint = ray.Origin + (ray.Direction * distance);
                    outReport.ImpactNormal = normal;
                    outReport.ImpactDistance = distance;
                    return true;
                }
            }

            return false;
        }

        void AxisAlignedRectangleShape::AppendTo(std::list<Vector2>& vertices)
        {
            if (GetScale() > 0.0f)
            {
                const Vector2 scaledMin = GetScaledMin();
                const Vector2 scaledMax = GetScaledMax();
                vertices.push_back(Vector2(scaledMin.X, scaledMin.Y));
                vertices.push_back(Vector2(scaledMax.X, scaledMin.Y));
                vertices.push_back(Vector2(scaledMax.X, scaledMax.Y));
                vertices.push_back(Vector2(scaledMin.X, scaledMax.Y));
            }
        }
    }
}
#include <TH/Collision2D/CircleShape.h>
#include <TH/Collision2D/RaycastReport.h>
#include <TH/Collision2D/Algorithm/Raycast.h>
#include <Halak/Math.h>
using Halak::Math;

namespace TH
{
    namespace Collision2D
    {
        CircleShape::CircleShape()
            : Shape(ShapeType::Circle),
              radius(0.0f),
              radiusSquared(0.0f),
              scaledRadius(0.0f),
              scaledRadiusSquared(0.0f),
              revision(0)
        {
        }

        CircleShape::~CircleShape()
        {
        }

        float CircleShape::GetRadius() const
        {
            return radius;
        }
        
        void CircleShape::SetRadius(float value)
        {
            if (GetRadius() != value)
            {
                radius = value;
                radiusSquared = radius * radius;
                revision = 0;
            }
        }

        float CircleShape::GetScaledRadius()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return scaledRadius;
        }

        float CircleShape::GetScaledRadiusSquared()
        {
            if (revision != GetSpatialRevision())              
                UpdateParameters();

            return scaledRadiusSquared;
        }

        void CircleShape::UpdateParameters()
        {
            revision = GetSpatialRevision();
            scaledRadius = GetRadius() * GetScale();
            scaledRadiusSquared = scaledRadius * scaledRadius;
        }

        bool CircleShape::Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback)
        {
            float outDistance = 0.0f;
            if (Algorithm::RaycastCircle(ray.Origin, ray.Direction, GetPosition(), GetScaledRadiusSquared(), outDistance) && outDistance <= ray.Length)
            {
                if (callback == nullptr || callback->OnHit(distance * distance))
                {
                    outReport.ImpactShape = this;
                    outReport.ImpactPoint = ray.Origin + (ray.Direction * distance);
                    outReport.ImpactNormal = report.ImpactPoint - GetPosition();
                    outReport.ImpactNormal.Normalize();
                    outReport.ImpactDistance = distance;
                    return true;
                }
            }

            return false;
        }

        void CircleShape::AppendTo(std::list<Vector2>& vertices)
        {
            const float scaledRadius = GetScaledRadius();
            if (scaledRadius > 0.0f)
            {
                const Vector2 center = GetPosition();
                const float increment = Math::TwoPi / 32.0f;
                for (float r = 0.0f; r < Math::TwoPi; r += increment)
                {
                    vertices.push_back(Vector2(center.X + scaledRadius * Math::Sin(r),
                                               center.Y + scaledRadius * Math::Cos(r)));
                }
            }
        }
    }
}
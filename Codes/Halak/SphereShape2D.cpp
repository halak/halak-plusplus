#include <Halak/PCH.h>
#include <Halak/SphereShape2D.h>
#include <Halak/Geom2D.h>
#include <Halak/Math.h>
#include <Halak/RaycastReport2D.h>

namespace Halak
{
    SphereShape2D::SphereShape2D()
        : Shape2D(Shape2D::SphereType),
          radius(0.0f),
          radiusSquared(0.0f),
          scaledRadius(0.0f),
          scaledRadiusSquared(0.0f),
          revision(0)
    {
    }

    SphereShape2D::~SphereShape2D()
    {
    }

    float SphereShape2D::GetRadius() const
    {
        return radius;
    }
    
    void SphereShape2D::SetRadius(float value)
    {
        if (GetRadius() != value)
        {
            radius = value;
            radiusSquared = radius * radius;
            revision = 0;
        }
    }

    float SphereShape2D::GetScaledRadius()
    {
        if (revision != GetSpatialRevision())
            UpdateParameters();

        return scaledRadius;
    }

    float SphereShape2D::GetScaledRadiusSquared()
    {
        if (revision != GetSpatialRevision())              
            UpdateParameters();

        return scaledRadiusSquared;
    }

    void SphereShape2D::UpdateParameters()
    {
        revision = GetSpatialRevision();
        scaledRadius = GetRadius() * GetScale();
        scaledRadiusSquared = scaledRadius * scaledRadius;
    }

    bool SphereShape2D::Raycast(const Ray2D& ray, RaycastReport2D& outReport, IRaycastCallback2D* callback)
    {
        float distance = 0.0f;
        if (Geom2D::RaycastSphere(ray.Origin, ray.Direction, GetPosition(), GetScaledRadiusSquared(), distance) && distance <= ray.Length)
        {
            if (callback == nullptr || callback->OnHit(distance * distance))
            {
                outReport.ImpactShape = this;
                outReport.ImpactPoint = ray.Origin + (ray.Direction * distance);
                outReport.ImpactNormal = outReport.ImpactPoint - GetPosition();
                outReport.ImpactNormal.Normalize();
                outReport.ImpactDistance = distance;
                return true;
            }
        }

        return false;
    }

    void SphereShape2D::AppendTo(std::list<Vector2>& vertices)
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
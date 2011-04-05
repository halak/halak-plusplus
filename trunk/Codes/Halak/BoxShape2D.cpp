#include <TH/Collision2D/RectangleShape.h>
#include <TH/Collision2D/RaycastReport.h>
#include <TH/Collision2D/Algorithm/Raycast.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        RectangleShape::RectangleShape()
            : Shape(ShapeType::Rectangle),
              orientation(Vector2::Zero),
              extension(Vector2::Zero),
              center(Vector2::Zero),
              rotatedOrientation(Vector2::Zero),
              rotatedUp(Vector2::Zero),
              scaledExtension(Vector2::Zero),
              p0(Vector2::Zero), p1(Vector2::Zero), p2(Vector2::Zero), p3(Vector2::Zero),
              revision(0)
        {
        }

        RectangleShape::~RectangleShape()
        {
        }

        Vector2 RectangleShape::GetOrientation() const
        {
            return orientation;
        }

        void RectangleShape::SetOrientation(Vector2 value)
        {
            if (value != Vector2::Zero)
                value.Normalize();

            if (GetOrientation() != value)
            {
                orientation = value;
                revision = 0;
            }
        }
 
        Vector2 RectangleShape::GetExtension() const
        {
            return extension;
        }

        void RectangleShape::SetExtension(Vector2 value)
        {
            if (GetExtension() != value)
            {
                extension = value;
                revision = 0;
            }
        }

        Vector2 RectangleShape::GetCenter()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return center;
        }

        Vector2 RectangleShape::GetRotatedOrientation()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return rotatedOrientation;
        }

        Vector2 RectangleShape::GetRotatedUp()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return rotatedUp;
        }

        Vector2 RectangleShape::GetScaledExtension()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return scaledExtension;
        }

        Vector2 RectangleShape::GetP0()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return p0;
        }

        Vector2 RectangleShape::GetP1()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return p1;
        }

        Vector2 RectangleShape::GetP2()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return p2;
        }

        Vector2 RectangleShape::GetP3()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return p3;
        }

        void RectangleShape::UpdateParameters()
        {
            revision = GetSpatialRevision();
            center = GetPosition();
            rotatedOrientation = GetOrientation();
            rotatedOrientation.Rotate(GetRotation());
            rotatedUp = Vector2(+rotatedOrientation.Y, -rotatedOrientation.X);
            scaledExtension = GetExtension() * GetScale();
            p0 = center - (rotatedOrientation * scaledExtension.X) - (rotatedUp * scaledExtension.Y);
            p1 = center + (rotatedOrientation * scaledExtension.X) - (rotatedUp * scaledExtension.Y);
            p2 = center + (rotatedOrientation * scaledExtension.X) + (rotatedUp * scaledExtension.Y);
            p3 = center - (rotatedOrientation * scaledExtension.X) + (rotatedUp * scaledExtension.Y);
        }

        bool RectangleShape::Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback)
        {
            float distance = 0.0f;
            Vector2 normal = Vector2::Zero;
            if (Algorithm::RaycastRectangle(ray.Origin, ray.Direction, GetCenter(), GetRotatedOrientation(), GetScaledExtension(), distance, normal) && distance <= ray.Length)
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

        void RectangleShape::AppendTo(std::list<Vector2>& vertices)
        {
            vertices.push_back(GetP0());
            vertices.push_back(GetP1());
            vertices.push_back(GetP2());
            vertices.push_back(GetP3());
        }
    }
}
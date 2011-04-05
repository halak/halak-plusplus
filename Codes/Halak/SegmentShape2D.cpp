#include <TH/Collision2D/SegmentShape.h>
#include <TH/Collision2D/RaycastReport.h>
#include <TH/Collision2D/Algorithm/Raycast.h>
#include <Halak/Math.h>

namespace TH
{
    namespace Collision2D
    {
        SegmentShape::SegmentShape()
            : Shape(ShapeType::Segment),
              direction(Vector2::Zero),
              frontLength(0.0f),
              backLength(0.0f),
              startPoint(Vector2::Zero),
              endPoint(Vector2::Zero),
              rotatedDirection(Vector2::Zero),
              revision(0)
        {
        }

        SegmentShape::~SegmentShape()
        {
        }

        Vector2 SegmentShape::GetDirection() const
        {
            return direction;
        }

        void SegmentShape::SetDirection(Vector2 value)
        {
            if (value != Vector2::Zero)
                value.Normalize();

            if (GetDirection() != value)
            {
                direction = value;
                revision = 0;
            }
        }

        float SegmentShape::GetFrontLength() const
        {
            return frontLength;
        }

        void SegmentShape::SetFrontLength(float value)
        {
            value = std::max(value, 0.0f);

            if (GetFrontLength() != value)
            {
                frontLength = value;
                revision = 0;
            }
        }

        float SegmentShape::GetBackLength() const
        {
            return backLength;
        }

        void SegmentShape::SetBackLength(float value)
        {
            value = std::max(value, 0.0f);

            if (GetBackLength() != value)
            {
                backLength = value;
                revision = 0;
            }
        }

        Vector2 SegmentShape::GetStartPoint()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return startPoint;
        }

        Vector2 SegmentShape::GetEndPoint()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return endPoint;
        }

        float SegmentShape::GetLength() const
        {
            return GetFrontLength() + GetBackLength();
        }

        Vector2 SegmentShape::GetRotatedDirection()
        {
            if (revision != GetSpatialRevision())
                UpdateParameters();

            return rotatedDirection;
        }

        void SegmentShape::UpdateParameters()
        {
            revision = GetSpatialRevision();
            rotatedDirection = direction;
            rotatedDirection.Rotate(GetRotation());
            startPoint = GetPosition() + (rotatedDirection * GetBackLength()  * GetScale());
            endPoint   = GetPosition() + (rotatedDirection * GetFrontLength() * GetScale());
        }

        bool SegmentShape::Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback)
        {
            float distance = 0.0f;
            if (Algorithm::RaycastSegment(ray.Origin, ray.Direction, ray.Length, GetStartPoint(), GetEndPoint(), distance))
            {
                if (callback == nullptr || callback->OnHit(distance * distance))
                {
                    const Vector2 rotatedDirection = GetRotatedDirection();
                    outReport.ImpactShape = this;
                    outReport.ImpactPoint = ray.Origin + (ray.Direction * distance);
                    outReport.ImpactNormal = Vector2(rotatedDirection.Y, rotatedDirection.X);
                    outReport.ImpactDistance = distance;
                    if (outReport.ImpactNormal.Dot(rotatedDirection) > 0.0f)
                        outReport.ImpactNormal = -report.ImpactNormal;

                    return true;
                }
            }

            return false;
        }

        void SegmentShape::AppendTo(std::list<Vector2>& vertices)
        {
            if (GetScale() > 0.0f && GetLength() > 0.0f)
            {
                vertices.push_back(GetStartPoint());
                vertices.push_back(GetEndPoint());
            }
        }
    }
}
#include <TH/Collision2D/Algorithm/IntersectShapes.h>
#include <TH/Collision2D/Algorithm/Intersect.h>
#include <TH/Collision2D/Shape.h>
#include <TH/Collision2D/PointShape.h>
#include <TH/Collision2D/SegmentShape.h>
#include <TH/Collision2D/CircleShape.h>
#include <TH/Collision2D/AxisAlignedRectangleShape.h>
#include <TH/Collision2D/RectangleShape.h>
#include <TH/Collision2D/UserShape.h>
#include <Halak/Math.h>
using Halak::Math;

namespace TH
{
    namespace Collision2D
    {
        namespace Algorithm
        {
            typedef bool (*F)(Shape*, Shape*);
            static const F IntersectFunctionTable[6][6] = 
            {
                { (F)IntersectShapePointPoint, (F)IntersectShapePointSegment,   (F)IntersectShapePointCircle,   (F)IntersectShapePointAxisAlignedRectangle,                (F)IntersectShapePointRectangle,                (F)IntersectShapePointUserShape                },
                { nullptr,                     (F)IntersectShapeSegmentSegment, (F)IntersectShapeSegmentCircle, (F)IntersectShapeSegmentAxisAlignedRectangle,              (F)IntersectShapeSegmentRectangle,              (F)IntersectShapeSegmentUserShape              },
                { nullptr,                     nullptr,                         (F)IntersectShapeCircleCircle,  (F)IntersectShapeCircleAxisAlignedRectangle,               (F)IntersectShapeCircleRectangle,               (F)IntersectShapeCircleUserShape               },
                { nullptr,                     nullptr,                         nullptr,                        (F)IntersectShapeAxisAlignedRectangleAxisAlignedRectangle, (F)IntersectShapeAxisAlignedRectangleRectangle, (F)IntersectShapeAxisAlignedRectangleUserShape },
                { nullptr,                     nullptr,                         nullptr,                        nullptr,                                                   (F)IntersectShapeRectangleRectangle,            (F)IntersectShapeRectangleUserShape            },
                { nullptr,                     nullptr,                         nullptr,                        nullptr,                                                   nullptr,                                        (F)IntersectShapeUserShapeUserShape            },
            };

            bool IntersectShapes(Shape* left, Shape* right)
            {
                if (left == nullptr || right == nullptr)
                    return false;

                if (static_cast<int>(left->GetType()) < static_cast<int>(right->GetType()))
                    return IntersectFunctionTable[left->GetType()][right->GetType()](left, right);
                else
                    return IntersectFunctionTable[right->GetType()][left->GetType()](right, left);
            }

            bool IntersectShapePointPoint(PointShape* left, PointShape* right)
            {
                return Math::Equals(left->GetPosition(), right->GetPosition());
            }

            bool IntersectShapePointSegment(PointShape* left, SegmentShape* right)
            {
                return IntersectPointSegment(left->GetPosition(), right->GetStartPoint(), right->GetEndPoint());
            }

            bool IntersectShapePointCircle(PointShape* left, CircleShape* right)
            {
                return Vector2::GetDistanceSquared(left->GetPosition(), right->GetPosition()) <= right->GetScaledRadiusSquared();
            }

            bool IntersectShapePointAxisAlignedRectangle(PointShape* left, AxisAlignedRectangleShape* right)
            {
                const Vector2 point = left->GetPosition();
                const Vector2 min = right->GetScaledMin();
                const Vector2 max = right->GetScaledMax(); 

                return min.X <= point.X && point.X <= max.X &&
                       min.Y <= point.Y && point.Y <= max.Y;
            }

            bool IntersectShapePointRectangle(PointShape* left, RectangleShape* right)
            {
                return IntersectPointRectangle(left->GetPosition(), right->GetCenter(), right->GetRotatedOrientation(), right->GetRotatedUp(), right->GetScaledExtension());
            }

            bool IntersectShapePointUserShape(PointShape* left, UserShape* right)
            {
                if (right->GetUserShape())
                    return right->GetUserShape()->IntersectPoint(right, left->GetPosition());
                else
                    return false;
            }

            bool IntersectShapeSegmentSegment(SegmentShape* left, SegmentShape* right)
            {
                return IntersectSegmentSegment(left->GetStartPoint(), left->GetEndPoint(), right->GetStartPoint(), right->GetEndPoint());
            }

            bool IntersectShapeSegmentCircle(SegmentShape* left, CircleShape* right)
            {
                return GetPointSegmentDistanceSquared(right->GetPosition(), left->GetStartPoint(), left->GetEndPoint()) <= right->GetScaledRadiusSquared();
            }

            bool IntersectShapeSegmentAxisAlignedRectangle(SegmentShape* left, AxisAlignedRectangleShape* right)
            {
                return IntersectSegmentAxisAlignedRectangle(left->GetStartPoint(), left->GetEndPoint(), right->GetScaledMin(), right->GetScaledMax());
            }

            bool IntersectShapeSegmentRectangle(SegmentShape* /*left*/, RectangleShape* /*right*/)
            {
                return false;
            }

            bool IntersectShapeSegmentUserShape(SegmentShape* left, UserShape* right)
            {
                if (right->GetUserShape())
                    return right->GetUserShape()->IntersectSegment(right, left->GetStartPoint(), left->GetEndPoint());
                else
                    return false;
            }

            bool IntersectShapeCircleCircle(CircleShape* left, CircleShape* right)
            {
                const float scaledRadiusSum = left->GetScaledRadius() + right->GetScaledRadius();
                return Vector2::GetDistanceSquared(left->GetPosition(), right->GetPosition()) <= (scaledRadiusSum * scaledRadiusSum);
            }

            bool IntersectShapeCircleAxisAlignedRectangle(CircleShape* left, AxisAlignedRectangleShape* right)
            {
                return GetPointAxisAlignedRectangleDistanceSquared(left->GetPosition(), right->GetScaledMin(), right->GetScaledMax()) <= left->GetScaledRadiusSquared();
            }

            bool IntersectShapeCircleRectangle(CircleShape* left, RectangleShape* right)
            {
                const Vector2 closestPoint = GetPointRectangleClosestPoint(left->GetPosition(), right->GetCenter(), right->GetRotatedOrientation(), right->GetRotatedUp(), right->GetScaledExtension());
                return Vector2::GetDistanceSquared(closestPoint, left->GetPosition()) <= left->GetScaledRadiusSquared();
            }

            bool IntersectShapeCircleUserShape(CircleShape* left, UserShape* right)
            {
                if (right->GetUserShape())
                    return right->GetUserShape()->IntersectCircle(right, left->GetPosition(), left->GetScaledRadius());
                else
                    return false;
            }

            bool IntersectShapeAxisAlignedRectangleAxisAlignedRectangle(AxisAlignedRectangleShape* left, AxisAlignedRectangleShape* right)
            {
                return IntersectAxisAlignedRectangleAxisAlignedRectangle(left->GetScaledMin(), left->GetScaledMax(), right->GetScaledMax(), right->GetScaledMax());
            }

            bool IntersectShapeAxisAlignedRectangleRectangle(AxisAlignedRectangleShape* /*left*/, RectangleShape* /*right*/)
            {
                return false;
            }

            bool IntersectShapeAxisAlignedRectangleUserShape(AxisAlignedRectangleShape* left, UserShape* right)
            {
                if (right->GetUserShape())
                    return right->GetUserShape()->IntersectAxisAlignedRectangle(right, left->GetScaledMin(), left->GetScaledMax());
                else
                    return false;
            }

            bool IntersectShapeRectangleRectangle(RectangleShape* left, RectangleShape* right)
            {
                return IntersectRectangleRectangle(left->GetCenter(), left->GetRotatedOrientation(), left->GetScaledExtension(), right->GetCenter(), right->GetRotatedOrientation(), right->GetScaledExtension());;
            }

            bool IntersectShapeRectangleUserShape(RectangleShape* left, UserShape* right)
            {
                if (right->GetUserShape())
                    return right->GetUserShape()->IntersectRectangle(right, left->GetCenter(), left->GetRotatedOrientation(), left->GetRotatedUp(), left->GetExtension());
                else
                    return false;
            }

            bool IntersectShapeUserShapeUserShape(UserShape* left, UserShape* right)
            {
                if (left->GetUserShape() && right->GetUserShape())
                    return left->GetUserShape()->IntersectUserShape(left, right->GetUserShape().GetPointee());
                else
                    return false;
            }
        }
    }
}
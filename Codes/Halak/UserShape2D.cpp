#include <TH/Collision2D/UserShape.h>

namespace TH
{
    namespace Collision2D
    {
        UserShape::UserShape()
            : Shape(ShapeType::User)
        {
        }

        UserShape::UserShape(IUserShapePtr userShape)
            : Shape(ShapeType::User),
              userShape(userShape)
        {
        }

        UserShape::~UserShape()
        {
        }

        IUserShapePtr UserShape::GetUserShape()
        {
            return userShape;
        }

        void UserShape::SerUserShape(IUserShapePtr value)
        {
            userShape = value;
        }

        bool UserShape::Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback)
        {
            if (GetUserShape())
                return GetUserShape()->Raycast(this, ray, outReport, callback);
            else
                return false;
        }

        void UserShape::AppendTo(std::list<Vector2>& vertices)
        {
            if (GetUserShape())
                GetUserShape()->AppendTo(this, vertices);
        }
    }
}
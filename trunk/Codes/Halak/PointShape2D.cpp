#include <TH/Collision2D/PointShape.h>

namespace TH
{
    namespace Collision2D
    {
        PointShape::PointShape()
            : Shape(ShapeType::Point)
        {
        }

        PointShape::~PointShape()
        {
        }

        bool PointShape::Raycast(const Ray2D& /*ray*/, RaycastReport& /*outReport*/, IRaycastCallback* /*callback*/)
        {
            return false;
        }

        void PointShape::AppendTo(std::list<Vector2>& vertices)
        {
            vertices.push_back(GetPosition());
        }
    }
}
#include <Halak/PCH.h>
#include <Halak/PointShape2D.h>

namespace Halak
{
    PointShape2D::PointShape2D()
        : Shape2D(Shape2D::PointType)
    {
    }

    PointShape2D::~PointShape2D()
    {
    }

    bool PointShape2D::Raycast(const Ray2D& /*ray*/, RaycastReport2D& /*outReport*/, IRaycastCallback2D* /*callback*/)
    {
        return false;
    }

    void PointShape2D::AppendTo(std::list<Vector2>& vertices)
    {
        vertices.push_back(GetPosition());
    }
}
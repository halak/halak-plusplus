#include <TH/Collision2D/Shape.h>
#include <TH/Collision2D/Algorithm/IntersectShapes.h>

namespace TH
{
    namespace Collision2D
    {
        Shape::Shape(ShapeType::E type)
            : type(type),
              position(Vector2::Zero),
              rotation(0.0f),
              scale(1.0f),
              revision(1)
        {
        }

        Shape::~Shape()
        {
        }

        void Shape::SetPosition(Vector2 value)
        {
            if (GetPosition() != value)
            {
                position = value;
                revision++;
            }
        }

        void Shape::SetRotation(float value)
        {
            if (GetRotation() != value)
            {
                rotation = value;
                revision++;
            }
        }

        void Shape::SetScale(float value)
        {
            if (GetScale() != value)
            {
                scale = value;
                revision++;
            }
        }

        bool Shape::Intersects(Shape* left, Shape* right)
        {
            return Algorithm::IntersectShapes(left, right);
        }
    }
}
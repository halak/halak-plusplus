#include <Halak/PCH.h>
#include <Halak/Ray2D.h>

namespace Halak
{
    void Ray2D::Normalize()
    {
        if (Direction != Vector2::Zero)
            Length *= Direction.Normalize();
    }
}
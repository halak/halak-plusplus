#include <Halak/Ray.h>
#include <Halak/Matrix4.h>
#include <Halak/Rectangle.h>

namespace Halak
{
    const Ray Ray::Empty;

    Ray Ray::FromScreenSpace(Point point, const Matrix4& viewTransform, const Matrix4& projectionTransform, const Rectangle& viewport)
    {
        const Vector3 v(+(((static_cast<float>(point.X) * 2.0f) / static_cast<float>(viewport.Width))  - 1.0f) / projectionTransform.M00,
                        -(((static_cast<float>(point.Y) * 2.0f) / static_cast<float>(viewport.Height)) - 1.0f) / projectionTransform.M11,
                        1.0f);

        const Matrix4 inversedViewTransform = Matrix4::Inversion(viewTransform);
        Vector3 direction((v.X * inversedViewTransform.M00) + (v.Y * inversedViewTransform.M10) + (v.Z * inversedViewTransform.M20),
                          (v.X * inversedViewTransform.M01) + (v.Y * inversedViewTransform.M11) + (v.Z * inversedViewTransform.M21),
                          (v.X * inversedViewTransform.M02) + (v.Y * inversedViewTransform.M12) + (v.Z * inversedViewTransform.M22));
        direction.Normalize();

        const Vector3 origin(inversedViewTransform.M30, inversedViewTransform.M31, inversedViewTransform.M32);

        return Ray(origin, direction, 1.0f);
    }
}
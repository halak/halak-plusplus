#ifndef __HALAK_MATH_INL__
#define __HALAK_MATH_INL__

namespace Halak
{
    int Math::Interpolate(int a, int b, float t)
    {
        return a + static_cast<int>(static_cast<float>(b - a) * t);
    }

    float Math::Interpolate(float a, float b, float t)
    {
        return a + (b - a) * t;
    }

    double Math::Interpolate(double a, double b, float t)
    {
        return a + (b - a) * static_cast<double>(t);
    }

    Point Math::Interpolate(Point a, Point b, float t)
    {
        return Point(Interpolate(a.X, b.X, t),
                     Interpolate(a.Y, b.Y, t));
    }

    Vector2 Math::Interpolate(Vector2 a, Vector2 b, float t)
    {
        return Vector2(Interpolate(a.X, b.X, t),
                       Interpolate(a.Y, b.Y, t));
    }

    Vector3 Math::Interpolate(Vector3 a, Vector3 b, float t)
    {
        return Vector3(Interpolate(a.X, b.X, t),
                       Interpolate(a.Y, b.Y, t),
                       Interpolate(a.Z, b.Z, t));
    }

    Vector4 Math::Interpolate(Vector4 a, Vector4 b, float t)
    {
        return Vector4(Interpolate(a.X, b.X, t),
                       Interpolate(a.Y, b.Y, t),
                       Interpolate(a.Z, b.Z, t),
                       Interpolate(a.W, b.W, t));
    }

    Color Math::Interpolate(Color a, Color b, float t)
    {
        return Color(Interpolate(static_cast<int>(a.R), static_cast<int>(b.R), t),
                     Interpolate(static_cast<int>(a.G), static_cast<int>(b.G), t),
                     Interpolate(static_cast<int>(a.B), static_cast<int>(b.B), t),
                     Interpolate(static_cast<int>(a.A), static_cast<int>(b.A), t));
    }
}

#endif
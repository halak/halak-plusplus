#include <Halak/Vector4.h>

namespace Halak
{
    Vector4::Vector4()
        : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
    {
    }

    Vector4::Vector4(float X, float Y, float Z)
        : X(X), Y(Y), Z(Z), W(0.0f)
    {
    }

    Vector4::Vector4(float X, float Y, float Z, float W)
        : X(X), Y(Y), Z(Z), W(W)
    {
    }

    Vector4::Vector4(const Vector3& original, float W)
        : X(original.X), Y(original.Y), Z(original.Z), W(W)
    {
    }

    Vector4::Vector4(const Vector4& original)
        : X(original.X), Y(original.Y), Z(original.Z), W(original.W)
    {
    }
    
    const Vector4 Vector4::Zero  = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    const Vector4 Vector4::UnitX = Vector4(1.0f, 0.0f, 0.0f, 0.0f);
    const Vector4 Vector4::UnitY = Vector4(0.0f, 1.0f, 0.0f, 0.0f);
    const Vector4 Vector4::UnitZ = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
    const Vector4 Vector4::UnitW = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    const Vector4 Vector4::One   = Vector4(1.0f, 1.0f, 1.0f, 1.0f);;
}
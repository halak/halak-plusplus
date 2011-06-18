#include <Halak/PCH.h>
#include <Halak/Matrix4.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   include <d3dx9math.h>

    namespace Halak
    {
        Matrix4 Matrix4::Inversion(const Matrix4& value)
        {
            D3DXMATRIX result;
            D3DXMatrixInverse(&result, NULL, reinterpret_cast<const D3DXMATRIX*>(&value.M00));
            return Matrix4(static_cast<const float*>(result));
        }
    }

#endif
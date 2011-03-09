#if (defined(WIN32) || defined(WIN64))

#   include <Halak/Matrix4.h>
#   include <d3dx9math.h>

    namespace Halak
    {
        Matrix4 Inversion(const Matrix4& value)
        {
            D3DXMATRIX result;
            D3DXMatrixInverse(&result, nullptr, reinterpret_cast<const D3DXMATRIX*>(&value.M00));
            return Matrix4(static_cast<const float*>(result));
        }
    }

#endif
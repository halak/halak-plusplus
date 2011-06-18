#include <Halak/PCH.h>
#include <Halak/UITransform3D.h>
#include <Halak/UIVisualVisitor.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   include <d3dx9math.h>

    namespace Halak
    {
        const Matrix4& UITransform3D::ComputeMatrix(UIVisual* /*owner*/, UIVisualVisitor& visitor)
        {
            const RectangleF bounds = visitor.GetCurrentBounds();

            if (matrixChanged || lastBounds != bounds)
            {
                D3DXQUATERNION d3dRotation;
                D3DXQuaternionRotationYawPitchRoll(&d3dRotation, rotation.Y, rotation.X, rotation.Z);
                
                const D3DXVECTOR3 d3dScaleCenter = D3DXVECTOR3(localOffset.X + bounds.X + (bounds.Width * scaleCenter.X),
                                                               localOffset.Y + bounds.Y + (bounds.Height * scaleCenter.Y),
                                                               localOffset.Z);
                const D3DXVECTOR3 d3dScale = D3DXVECTOR3(scale.X, scale.Y, 1.0f);
                const D3DXVECTOR3 d3dRotationCenter = D3DXVECTOR3(localOffset.X + bounds.X + (bounds.Width * rotationCenter.X),
                                                                  localOffset.Y + bounds.Y + (bounds.Height * rotationCenter.Y),
                                                                  localOffset.Z);
                const D3DXVECTOR3 d3dTranslation = D3DXVECTOR3(globalOffset.X, globalOffset.Y, globalOffset.Z);

                D3DXMATRIX d3dResultTransform;
                D3DXMatrixTransformation(&d3dResultTransform, &d3dScaleCenter, nullptr, &d3dScale, &d3dRotationCenter, &d3dRotation, &d3dTranslation);

                matrix = Matrix4(d3dResultTransform);
                matrixChanged = false;
                lastBounds = bounds;
            }

            return matrix;
        }
    }

#endif
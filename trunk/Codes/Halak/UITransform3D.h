#pragma once
#ifndef __HALAK_UITRANSFORM3D_H__
#define __HALAK_UITRANSFORM3D_H__

#   include <Halak/UITransform.h>
#   include <Halak/RectangleF.h>
#   include <Halak/Vector2.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        class UITransform3D : public UITransform
        {
            public:
                UITransform3D();
                virtual ~UITransform3D();

                virtual const Matrix4& ComputeMatrix(UIVisual* owner, UIVisualVisitor& visitor);

                void Reset();

                inline Vector3 GetLocalOffset() const;
                void SetLocalOffset(Vector3 value);

                inline Vector3 GetGlobalOffset() const;
                void SetGlobalOffset(Vector3 value);

                inline Vector2 GetRotationCenter() const;
                void SetRotationCenter(Vector2 value);

                inline Vector3 GetRotation() const;
                void SetRotation(Vector3 value);

                inline Vector2 GetScaleCenter() const;
                void SetScaleCenter(Vector2 value);

                inline Vector2 GetScale() const;
                void SetScale(Vector2 value);

            private:
                Vector3 localOffset;
                Vector3 globalOffset;
                Vector2 rotationCenter;
                Vector3 rotation;
                Vector2 scaleCenter;
                Vector2 scale;
                Matrix4 matrix;
                RectangleF lastBounds;
                bool matrixChanged;
        };
    }

#   include <Halak/UITransform3D.inl>

#endif
#pragma once
#ifndef __HALAK_UIVISUALVISITOR_H__
#define __HALAK_UIVISUALVISITOR_H__

#   include <Halak/FWD.h>
#   include <Halak/Matrix4.h>
#   include <Halak/RectangleF.h>

    namespace Halak
    {
        class UIVisualVisitor
        {
            HKThisIsNoncopyableClass(UIVisualVisitor);
            public:
                UIVisualVisitor();
                UIVisualVisitor(float fieldOfView, bool visibleOnly);
                virtual ~UIVisualVisitor();

                Vector2 Project(Vector2 point) const;
                Vector2 Unproject(Vector2 point) const;
                Vector2 UnprojectByParent(Vector2 point) const;

                void Project(Vector2* inOutPoints, int count) const;

                inline float GetFieldOfView() const;
                inline bool GetVisibleOnly() const;

                inline UIVisual* GetCurrentVisual() const;
                inline float GetCurrentOpacity() const; 
                inline const RectangleF& GetCurrentBounds() const;
                inline const RectangleF& GetCurrentClippedBounds() const;
                inline const Matrix4& GetCurrentTransform() const;

            protected:
                void Visit(UIVisual* target);

                virtual void OnVisit(UIVisual* target) = 0;

            private:
                float fieldOfView;
                bool visibleOnly;

                UIVisualPtr currentVisual;
                float currentOpacity;
                RectangleF currentBounds;
                RectangleF currentClippedBounds;
                Matrix4 currentTransform;
                Matrix4 currentTransformInv;
                Matrix4 parentTransform;
                Matrix4 parentTransformInv;
                Matrix4 projectionTransform;
                Matrix4 viewTransform;
                Matrix4 viewTransformInv;
        };
    }

#   include <Halak/UIVisualVisitor.inl>

#endif
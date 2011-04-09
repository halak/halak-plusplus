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
                virtual ~UIVisualVisitor();

                void Visit(const UIVisualPtr& target);

                inline bool GetVisibleOnly() const;
                inline void SetVisibleOnly(bool value);

                inline const UIVisualPtr& GetCurrentVisual() const;
                inline float GetCurrentOpacity() const;
                inline const RectangleF& GetCurrentBounds() const;
                inline const RectangleF& GetCurrentClippedBounds() const;
                inline const Matrix4& GetCurrentTransform() const;

            protected:
                virtual void OnWork(const UIVisualPtr& target) = 0;

            private:
                bool visibleOnly;

                UIVisualPtr currentVisual;
                float currentOpacity;
                RectangleF currentBounds;
                RectangleF currentClippedBounds;
                Matrix4 currentTransform;
        };
    }

#   include <Halak/UIVisualVisitor.inl>

#endif
#pragma once
#ifndef __HALAK_UIPICKINGCONTEXT_H__
#define __HALAK_UIPICKINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisualVisitor.h>

    namespace Halak
    {
        class UIPickingContext : public UIVisualVisitor
        {
            public:
                UIPickingContext(Vector2 point);
                UIPickingContext(float fieldOfView, bool visibleOnly, Vector2 point);
                virtual ~UIPickingContext();

                bool Pick(UIVisual* target);

                inline bool Contains(const RectangleF& bounds);

                inline Vector2 GetPoint() const;
                inline Vector2 GetCurrentPoint() const;

                inline UIVisual* GetResult() const;
                void SetResult(UIVisual* value);

            protected:
                virtual void OnVisit(UIVisual* target);

            private:
                Vector2 point;
                Vector2 currentPoint;
                UIVisual* result;
        };
    }

#   include <Halak/UIPickingContext.inl>

#endif
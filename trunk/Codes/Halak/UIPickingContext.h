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
                UIPickingContext(UIRenderer* renderer, Vector2 point);
                UIPickingContext(UIRenderer* renderer, Vector2 point, bool visibleOnly);
                virtual ~UIPickingContext();

                bool Pick(UIVisual* target);

                inline bool Contains(const RectangleF& bounds);

                inline Vector2 GetPoint() const;
                inline Vector2 GetCurrentPoint() const;

                inline UIVisual* GetResult() const;
                void SetResult(UIVisual* value);

            protected:
                virtual void OnVisit();

            private:
                Vector2 point;
                Vector2 currentPoint;
                UIVisual* result;
        };
    }

#   include <Halak/UIPickingContext.inl>

#endif
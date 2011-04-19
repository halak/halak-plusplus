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
                virtual ~UIPickingContext();

                bool Pick(UIVisual* target);

                inline Vector2 GetPoint() const;

                inline UIVisual* GetResult() const;
                void SetResult(UIVisual* value);

            protected:
                virtual void OnVisit(UIVisual* target);

            private:
                Vector2 point;
                UIVisual* result;
        };
    }

#   include <Halak/UIPickingContext.inl>

#endif
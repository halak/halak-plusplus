#pragma once
#ifndef __HALAK_UIDRAWINGCONTEXT_H__
#define __HALAK_UIDRAWINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisualVisitor.h>

    namespace Halak
    {
        class UIDrawingContext : public UIVisualVisitor
        {
            public:
                UIDrawingContext(UIRenderer* renderer);
                virtual ~UIDrawingContext();

                void Draw(const RectangleF& bounds, UIImage* image, const RectangleF& clippingRectangle);
                void DrawRectangle(const RectangleF& bounds, Color color);

            protected:
                virtual void OnVisit(UIVisual* target);

            private:
                UIRenderer* renderer;
        };
    }

#   include <Halak/UIDrawingContext.inl>

#endif
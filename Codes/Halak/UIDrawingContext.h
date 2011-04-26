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
                UIDrawingContext(SpriteRenderer* renderer);
                virtual ~UIDrawingContext();

                inline void Draw(UIVisual* target);

                inline void Draw(UIImage* image);
                inline void Draw(UIImage* image, bool horizontalFlip, bool verticalFlip);
                void Draw(const RectangleF& bounds, const RectangleF& clippedBounds, UIImage* image, bool horizontalFlip, bool verticalFlip);
                inline void DrawString(Font* font, const String& text);
                void DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, Font* font, const String& text);
                inline void DrawString(const FontString& fontString);
                void DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, const FontString& fontString);
                void DrawRectangle(const RectangleF& bounds, Color color);

            protected:
                virtual void OnVisit(UIVisual* target);

            private:
                SpriteRenderer* renderer;
        };
    }

#   include <Halak/UIDrawingContext.inl>

#endif
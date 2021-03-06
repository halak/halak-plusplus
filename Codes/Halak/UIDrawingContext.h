#pragma once
#ifndef __HALAK_UIDRAWINGCONTEXT_H__
#define __HALAK_UIDRAWINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisualVisitor.h>
#    include <Halak/Vector2.h>

    namespace Halak
    {
        class UIDrawingContext : public UIVisualVisitor
        {
            public:
                UIDrawingContext(UIRenderer* renderer);
                virtual ~UIDrawingContext();

                void Draw(UIVisual* target);

                inline void Draw(UIImage* image);
                inline void Draw(UIImage* image, bool horizontalFlip, bool verticalFlip);
                void Draw(const RectangleF& bounds, const RectangleF& clippedBounds, UIImage* image, bool horizontalFlip, bool verticalFlip);
                void Draw(Vector2 position, Texture2D* texture);

                inline void DrawString(Font* font, const String& text);
                inline void DrawString(const FontString& fontString);
                inline void DrawString(Vector2 position, Font* font, const String& text);
                void DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, Font* font, const String& text);
                void DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, const FontString& fontString);
                void DrawRectangle(const RectangleF& bounds, float width, Color color);

                void FillRectangle(const RectangleF& bounds, float width, Color color);

            protected:
                inline void DrawChild(UIVisual* target);

                virtual void OnBegan();
                virtual void OnEnded();
                virtual void OnVisit();               

            private:
                UIRenderer* renderer;
                bool isDrawing;

                friend class UIPanel;
        };
    }

#   include <Halak/UIDrawingContext.inl>

#endif
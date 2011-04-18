#pragma once
#ifndef __HALAK_UISPRITE_H__
#define __HALAK_UISPRITE_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UISprite : public UIVisual
        {
            public:
                UISprite();
                virtual ~UISprite();

                inline UIImage* GetImage() const;
                void SetImage(UIImage* value);

                inline bool GetAutoResize() const;
                void SetAutoResize(bool value);

                inline bool GetHorizontalFlip() const;
                inline void SetHorizontalFlip(bool value);

                inline bool GetVerticalFlip() const;
                inline void SetVerticalFlip(bool value);

            protected:
                virtual void OnDraw(UIDrawingContext& context);

            private:
                void ResizeToImageSize();

            private:
                UIImagePtr image;
                bool autoResize;
                bool horizontalFlip;
                bool verticalFlip;
        };
    }

#   include <Halak/UISprite.inl>

#endif
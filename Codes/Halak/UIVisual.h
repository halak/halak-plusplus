#pragma once
#ifndef __HALAK_UIVISUAL_H__
#define __HALAK_UIVISUAL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIElement.h>

    namespace Halak
    {
        class UIVisual : public UIElement
        {
            public:
                UIVisual();
                virtual ~UIVisual();

                inline float GetOpacity() const;
                void SetOpacity(float value);

                inline bool GetShown() const;
                void SetShown(bool value);

                inline const UIFramePtr& GetFrame() const;
                void SetFrame(const UIFramePtr& value);

                inline const UIWindowWeakPtr& GetParent() const;

                inline bool IsVisible() const;
                virtual bool IsWindow() const;

            protected:
                virtual void OnDraw(UIDrawingContext& context);

                virtual void OnOpacityChanged(float old);
                virtual void OnShownChanged();
                virtual void OnFrameChanged(const UIFramePtr& old);
                virtual void OnParentChanged(const UIWindowWeakPtr& old);

            private:
                void SetParent(const UIWindowWeakPtr& value);

            private:
                float opacity;
                bool shown;
                UIFramePtr frame;
                UIWindowWeakPtr parent;

                friend class UIDrawingContext;
                friend class UIWindow;
        };
    }

#   include <Halak/UIVisual.inl>

#endif
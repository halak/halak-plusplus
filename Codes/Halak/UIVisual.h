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

                inline UIFrame* GetFrame() const;
                void SetFrame(UIFrame* value);

                inline UIWindow* GetParent() const;

                inline bool IsVisible() const;
                virtual bool IsWindow() const;

            protected:
                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnPick(UIPickingContext& context);

                virtual void OnOpacityChanged(float old);
                virtual void OnShownChanged();
                virtual void OnFrameChanged(UIFrame* old);
                virtual void OnParentChanged(UIWindow* old);

            private:
                void SetParent(UIWindow* value);

            private:
                float opacity;
                bool shown;
                UIFramePtr frame;
                UIWindowWeakPtr parent;

                friend class UIDrawingContext;
                friend class UIPickingContext;
                friend class UIWindow;
        };
    }

#   include <Halak/UIVisual.inl>

#endif
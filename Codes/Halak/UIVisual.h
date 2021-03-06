#pragma once
#ifndef __HALAK_UIVISUAL_H__
#define __HALAK_UIVISUAL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIElement.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class UIVisual : public UIElement
        {
            public:
                static const Property<float> OpacityProperty;
                static const Property<bool>  ShownProperty;

            public:
                UIVisual();
                virtual ~UIVisual();

                inline void Show();
                inline void Hide();

                void BringToFront();
                void SendToBack();

                RectangleF ComputeBounds(UIVisualVisitor& visitor);

                inline float GetOpacity() const;
                void SetOpacity(float value);

                inline bool GetShown() const;
                inline void SetShown(bool value);

                inline UIFrame* GetFrame() const;
                void SetFrame(UIFrame* value);

                inline UITransform* GetTransform() const;
                void SetTransform(UITransform* value);

                inline UIEventMap* GetEventMap() const;
                void SetEventMap(UIEventMap* value);

                inline virtual Vector2 GetDesiredSize();

                inline UIPanel* GetParent() const;

                inline bool IsVisible() const;
                virtual bool IsPanel() const;

            protected:
                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnPick(UIPickingContext& context);

                virtual void OnParentChanged(UIPanel* old);

                virtual bool OnKeyDown(const UIKeyboardEventArgs& args);
                virtual bool OnKeyUp(const UIKeyboardEventArgs& args);
                virtual bool OnKeyPressing(const UIKeyboardEventArgs& args);
                virtual void OnMouseEnter(const UIMouseEventArgs& args);
                virtual void OnMouseLeave(const UIMouseEventArgs& args);
                virtual bool OnMouseMove(const UIMouseEventArgs& args);
                virtual bool OnMouseClick(const UIMouseEventArgs& args);
                virtual bool OnMouseButtonDown(const UIMouseButtonEventArgs& args);
                virtual bool OnMouseButtonUp(const UIMouseButtonEventArgs& args);
                virtual bool OnMouseButtonPressing(const UIMouseButtonEventArgs& args);
                virtual bool OnMouseWheel(const UIMouseWheelEventArgs& args);
                virtual bool OnGamePadButtonDown(const UIGamePadEventArgs& args);
                virtual bool OnGamePadButtonUp(const UIGamePadEventArgs& args);
                virtual bool OnGamePadButtonPressing(const UIGamePadEventArgs& args);
                virtual bool OnGamePadTrigger(const UIGamePadEventArgs& args);
                virtual bool OnGamePadThumbstick(const UIGamePadEventArgs& args);

            private:
                void SetParent(UIPanel* value);

                void RaiseKeyDownEvent(const UIKeyboardEventArgs& args);
                void RaiseKeyUpEvent(const UIKeyboardEventArgs& args);
                void RaiseKeyPressingEvent(const UIKeyboardEventArgs& args);
                void RaiseMouseEnterEvent(const UIMouseEventArgs& args);
                void RaiseMouseLeaveEvent(const UIMouseEventArgs& args);
                void RaiseMouseMoveEvent(const UIMouseEventArgs& args);
                void RaiseMouseClickEvent(const UIMouseEventArgs& args);
                void RaiseMouseButtonDownEvent(const UIMouseButtonEventArgs& args);
                void RaiseMouseButtonUpEvent(const UIMouseButtonEventArgs& args);
                void RaiseMouseButtonPressingEvent(const UIMouseButtonEventArgs& args);
                void RaiseMouseWheelEvent(const UIMouseWheelEventArgs& args);
                void RaiseGamePadButtonDownEvent(const UIGamePadEventArgs& args);
                void RaiseGamePadButtonUpEvent(const UIGamePadEventArgs& args);
                void RaiseGamePadButtonPressingEvent(const UIGamePadEventArgs& args);
                void RaiseGamePadTriggerEvent(const UIGamePadEventArgs& args);
                void RaiseGamePadThumbstickEvent(const UIGamePadEventArgs& args);

            private:
                float opacity;
                Vector2 size;
                bool shown;
                UIFramePtr frame;
                UITransformPtr transform;
                UIEventMapPtr eventMap;
                UIPanel* parent;

                friend class UIDrawingContext;
                friend class UIPickingContext;
                friend class UIKeyboardEventDispatcher;
                friend class UIMouseEventDispatcher;
                friend class UIGamdPadEventDispatcher;
                friend class UITouchEventDispatcher;
                friend class UIPanel;

                friend void __Startup__();
                static void __Startup__();
        };
    }

#   include <Halak/UIVisual.inl>

#endif
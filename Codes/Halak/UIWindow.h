#pragma once
#ifndef __HALAK_UIWINDOW_H__
#define __HALAK_UIWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace Halak
    {
        class UIWindow : public UIVisual
        {
            public:
                typedef std::vector<UIVisualPtr> VisualCollection;

            public:
                UIWindow();
                explicit UIWindow(int childrenCapacity);
                virtual ~UIWindow();

                void AddChild(UIVisual* item);
                void InsertChild(int index, UIVisual* item);
                bool RemoveChild(UIVisual* item);
                bool RemoveChildAt(int index);
                void RemoveAllChildren();

                UIVisual* FindChild(const String& name, bool searchAllChildren) const;

                inline const VisualCollection& GetChildren() const;

                virtual bool IsWindow() const;

                inline Signal<const UIKeyboardEventArgs&, bool&>& KeyDownEvent();
                inline Signal<const UIKeyboardEventArgs&, bool&>& KeyUpEvent();
                inline Signal<const UIKeyboardEventArgs&, bool&>& KeyPressingEvent();
                inline Signal<const UIMouseEventArgs&>& MouseEnterEvent();
                inline Signal<const UIMouseEventArgs&>& MouseLeaveEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseMoveEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseClickEvent();
                inline Signal<const UIMouseButtonEventArgs&, bool&>& MouseButtonDownEvent();
                inline Signal<const UIMouseButtonEventArgs&, bool&>& MouseButtonUpEvent();
                inline Signal<const UIMouseButtonEventArgs&, bool&>& MouseButtonPressingEvent();
                inline Signal<const UIMouseWheelEventArgs&, bool&>& MouseWheelEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& GamePadButtonDownEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& GamePadButtonUpEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& GamePadButtonPressingEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& GamePadTriggerEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& GamePadThumbstickEvent();

            protected:
                void DrawChildren(UIDrawingContext& context);

                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnPick(UIPickingContext& context);
                virtual void OnChildAdded(UIVisual* child);
                virtual void OnChildRemoved(UIVisual* child);
                virtual void OnChildrenAdded(const VisualCollection& children);
                virtual void OnChildrenRemoved(const VisualCollection& children);

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
                void RemoveChildByIterator(VisualCollection::iterator it);

                void BringChildToFront(UIVisual* child);
                void SendChildToBack(UIVisual* child);

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
                VisualCollection children;

                Signal<const UIKeyboardEventArgs&, bool&> keyDownEvent;
                Signal<const UIKeyboardEventArgs&, bool&> keyUpEvent;
                Signal<const UIKeyboardEventArgs&, bool&> keyPressingEvent;
                Signal<const UIMouseEventArgs&> mouseEnterEvent;
                Signal<const UIMouseEventArgs&> mouseLeaveEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseMoveEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseClickEvent;
                Signal<const UIMouseButtonEventArgs&, bool&> mouseButtonDownEvent;
                Signal<const UIMouseButtonEventArgs&, bool&> mouseButtonUpEvent;
                Signal<const UIMouseButtonEventArgs&, bool&> mouseButtonPressingEvent;
                Signal<const UIMouseWheelEventArgs&, bool&> mouseWheelEvent;
                Signal<const UIGamePadEventArgs&, bool&> gamePadButtonDownEvent;
                Signal<const UIGamePadEventArgs&, bool&> gamePadButtonUpEvent;
                Signal<const UIGamePadEventArgs&, bool&> gamePadButtonPressingEvent;
                Signal<const UIGamePadEventArgs&, bool&> gamePadTriggerEvent;
                Signal<const UIGamePadEventArgs&, bool&> gamePadThumbstickEvent;

                friend class UIKeyboardEventDispatcher;
                friend class UIMouseEventDispatcher;
                friend class UIGamdPadEventDispatcher;
                friend class UITouchEventDispatcher;
                friend class UIVisual;
        };
    }

#   include <Halak/UIWindow.inl>

#endif
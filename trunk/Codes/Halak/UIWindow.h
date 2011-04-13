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

                void AddChild(const UIVisualPtr& item);
                void InsertChild(int index, const UIVisualPtr& item);
                bool RemoveChild(const UIVisualPtr& item);
                bool RemoveChildAt(int index);
                void RemoveAllChildren();

                UIVisualPtr Find(const String& name, bool searchAllChildren) const;

                inline const VisualCollection& GetChildren() const;

                virtual bool IsWindow() const;

                inline Signal<const UIKeyboardEventArgs&, bool&>& KeyDownEvent();
                inline Signal<const UIKeyboardEventArgs&, bool&>& KeyUpEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseEnterEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseLeaveEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseMoveEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseLeftDownEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseLeftUpEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseRightDownEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseRightUpEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseMiddleDownEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseMiddleUpEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseWheelEvent();
                inline Signal<const UIMouseEventArgs&, bool&>& MouseClickEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& ButtonDownEvent();
                inline Signal<const UIGamePadEventArgs&, bool&>& ButtonUpEvent();

            protected:
                void DrawChildren(UIDrawingContext& context);

                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnChildAdded(const UIVisualPtr& child);
                virtual void OnChildRemoved(const UIVisualPtr& child);
                virtual void OnChildrenAdded(const VisualCollection& children);
                virtual void OnChildrenRemoved(const VisualCollection& children);

                virtual bool OnKeyDown(const UIKeyboardEventArgs& args);
                virtual bool OnKeyUp(const UIKeyboardEventArgs& args);
                virtual bool OnMouseEnter(const UIMouseEventArgs& args);
                virtual bool OnMouseLeave(const UIMouseEventArgs& args);
                virtual bool OnMouseMove(const UIMouseEventArgs& args);
                virtual bool OnMouseLeftDown(const UIMouseEventArgs& args);
                virtual bool OnMouseLeftUp(const UIMouseEventArgs& args);
                virtual bool OnMouseRightDown(const UIMouseEventArgs& args);
                virtual bool OnMouseRightUp(const UIMouseEventArgs& args);
                virtual bool OnMouseMiddleDown(const UIMouseEventArgs& args);
                virtual bool OnMouseMiddleUp(const UIMouseEventArgs& args);
                virtual bool OnMouseWheel(const UIMouseEventArgs& args);
                virtual bool OnMouseClick(const UIMouseEventArgs& args);
                virtual bool OnButtonDown(const UIGamePadEventArgs& args);
                virtual bool OnButtonUp(const UIGamePadEventArgs& args);

            private:
                void RemoveChildByIterator(VisualCollection::iterator it);

                void RaiseKeyDownEvent(const UIKeyboardEventArgs& args);
                void RaiseKeyUpEvent(const UIKeyboardEventArgs& args);
                void RaiseMouseEnterEvent(const UIMouseEventArgs& args);
                void RaiseMouseLeaveEvent(const UIMouseEventArgs& args);
                void RaiseMouseMoveEvent(const UIMouseEventArgs& args);
                void RaiseMouseLeftDownEvent(const UIMouseEventArgs& args);
                void RaiseMouseLeftUpEvent(const UIMouseEventArgs& args);
                void RaiseMouseRightDownEvent(const UIMouseEventArgs& args);
                void RaiseMouseRightUpEvent(const UIMouseEventArgs& args);
                void RaiseMouseMiddleDownEvent(const UIMouseEventArgs& args);
                void RaiseMouseMiddleUpEvent(const UIMouseEventArgs& args);
                void RaiseMouseWheelEvent(const UIMouseEventArgs& args);
                void RaiseMouseClickEvent(const UIMouseEventArgs& args);
                void RaiseButtonDownEvent(const UIGamePadEventArgs& args);
                void RaiseButtonUpEvent(const UIGamePadEventArgs& args);

            private:
                VisualCollection children;

                Signal<const UIKeyboardEventArgs&, bool&> keyDownEvent;
                Signal<const UIKeyboardEventArgs&, bool&> keyUpEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseEnterEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseLeaveEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseMoveEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseLeftDownEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseLeftUpEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseRightDownEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseRightUpEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseMiddleDownEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseMiddleUpEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseWheelEvent;
                Signal<const UIMouseEventArgs&, bool&> mouseClickEvent;
                Signal<const UIGamePadEventArgs&, bool&> buttonDownEvent;
                Signal<const UIGamePadEventArgs&, bool&> buttonUpEvent;

                friend class UIKeyboardEventDispatcher;
                friend class UIMouseEventDispatcher;
                friend class UIGamdPadEventDispatcher;
                friend class UITouchEventDispatcher;
        };
    }

#   include <Halak/UIWindow.inl>

#endif
namespace Halak
{
    const UIWindow::VisualCollection& UIWindow::GetChildren() const
    {
        return children;
    }

    Signal<const UIKeyboardEventArgs&, bool&>& UIWindow::KeyDownEvent()
    {
        return keyDownEvent;
    }

    Signal<const UIKeyboardEventArgs&, bool&>& UIWindow::KeyUpEvent()
    {
        return keyUpEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseEnterEvent()
    {
        return mouseEnterEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseLeaveEvent()
    {
        return mouseLeaveEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseMoveEvent()
    {
        return mouseMoveEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseLeftDownEvent()
    {
        return mouseLeftDownEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseLeftUpEvent()
    {
        return mouseLeftUpEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseRightDownEvent()
    {
        return mouseRightDownEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseRightUpEvent()
    {
        return mouseRightUpEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseMiddleDownEvent()
    {
        return mouseMiddleDownEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseMiddleUpEvent()
    {
        return mouseMiddleUpEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseWheelEvent()
    {
        return mouseWheelEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseClickEvent()
    {
        return mouseClickEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::ButtonDownEvent()
    {
        return buttonDownEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::ButtonUpEvent()
    {
        return buttonUpEvent;
    }
}
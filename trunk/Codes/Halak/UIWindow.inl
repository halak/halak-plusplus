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

    Signal<const UIKeyboardEventArgs&, bool&>& UIWindow::KeyPressingEvent()
    {
        return keyPressingEvent;
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

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseButtonDownEvent()
    {
        return mouseButtonDownEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseButtonUpEvent()
    {
        return mouseButtonUpEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseButtonPressingEvent()
    {
        return mouseButtonPressingEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseWheelEvent()
    {
        return mouseWheelEvent;
    }

    Signal<const UIMouseEventArgs&, bool&>& UIWindow::MouseClickEvent()
    {
        return mouseClickEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::GamePadButtonDownEvent()
    {
        return gamePadButtonDownEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::GamePadButtonUpEvent()
    {
        return gamePadButtonUpEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::GamePadButtonPressingEvent()
    {
        return gamePadButtonPressingEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::GamePadTriggerEvent()
    {
        return gamePadTriggerEvent;
    }

    Signal<const UIGamePadEventArgs&, bool&>& UIWindow::GamePadStickEvent()
    {
        return gamePadStickEvent;
    }
}
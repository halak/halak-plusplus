#include <Halak/PCH.h>
#include <Halak/UIMouseEventDispatcher.h>
#include <Halak/UIDomain.h>
#include <Halak/Mouse.h>
#include <Halak/UIMouseEventArgs.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIMouseEventDispatcher::UIMouseEventDispatcher()
        : lastTimestamp(0xFFFFFFFF),
          domain(nullptr),
          device(nullptr),
          capturedWindow(nullptr),
          lastTargetWindow(nullptr),
          lastMouseState(MouseState::Empty)
    {
    }

    UIMouseEventDispatcher::~UIMouseEventDispatcher()
    {
    }

    void UIMouseEventDispatcher::Update(float /*dt*/, uint timestamp)
    {
        if (lastTimestamp == timestamp ||
            domain == nullptr ||
            device == nullptr ||
            GetStatus() != ActiveStatus)
            return;

        lastTimestamp = timestamp;

        //UIWindowPtr targetWindow = windowTarget->GetTarget();
        //if (targetWindow == nullptr)
        //    return;

        //const MouseState& state = device->GetState();

        //UIPickingContext picker(Vector2(state.Position.X, state.Position.Y));

        //UIWindowPtr pickedWindow; // PICK
        //UIWindowPtr currentWindow;

        //if (capturedWindow)
        //    currentWindow = capturedWindow;
        //else
        //{
        //    if (picker.Pick(targetWindow))
        //        pickedWindow = picker.GetResult()->GetParent();
        //    else
        //        pickedWindow = targetWindow;

        //    currentWindow = pickedWindow;
        //}

        //const int wheelDelta = state.Wheel - lastState.Wheel;
        //const bool leftButtonPressed   = state.LeftButton == MouseState::PressedButton;
        //const bool rightButtonPressed  = state.RightButton == MouseState::PressedButton;
        //const bool middleButtonPressed = state.MiddleButton == MouseState::PressedButton;

        //UIMouseEventArgs mouseEventArgs = UIMouseEventArgs(currentWindow, state.Position, wheelDelta, leftButtonPressed, rightButtonPressed, middleButtonPressed);

        //if (currentWindow && lastState.Position != state.Position)
        //{
        //    currentWindow->RaiseMouseMoveEvent(mouseEventArgs);
        //}

        //if (lastWindow != currentWindow)
        //{
        //    if (lastWindow)
        //    {
        //        lastWindow->RaiseMouseLeaveEvent(UIMouseEventArgs(lastWindow,
        //                                                          state.Position,
        //                                                          wheelDelta,
        //                                                          leftButtonPressed, rightButtonPressed, middleButtonPressed));
        //    }

        //    if (currentWindow)
        //        currentWindow->RaiseMouseEnterEvent(mouseEventArgs);
        //}

        //if (currentWindow)
        //{
        //    if (wheelDelta != 0)
        //    {
        //        currentWindow->RaiseMouseWheelEvent(mouseEventArgs);
        //    }

        //    if (state.LeftButton == MouseState::PressedButton)
        //    {
        //        if (lastState.LeftButton == MouseState::ReleasedButton)
        //        {
        //            currentWindow->RaiseMouseLeftDownEvent(mouseEventArgs);
        //            capturedWindow = currentWindow;
        //            windowTarget->SetTarget(currentWindow);
        //        }
        //    }
        //    else
        //    {
        //        if (lastState.LeftButton == MouseState::PressedButton)
        //        {
        //            currentWindow->RaiseMouseLeftUpEvent(mouseEventArgs);

        //            if (pickedWindow == nullptr)
        //            {
        //                if (picker.Pick(targetWindow))
        //                    pickedWindow = picker.GetResult()->GetParent();
        //                else
        //                    pickedWindow = targetWindow;
        //            }

        //            if (currentWindow == pickedWindow)
        //                currentWindow->RaiseMouseClickEvent(mouseEventArgs);

        //            capturedWindow = nullptr;
        //        }
        //    }

        //    if (state.RightButton == MouseState::PressedButton)
        //    {
        //        if (lastState.RightButton == MouseState::ReleasedButton)
        //            currentWindow->RaiseMouseRightDownEvent(mouseEventArgs);
        //    }
        //    else
        //    {
        //        if (lastState.RightButton == MouseState::PressedButton)
        //            currentWindow->RaiseMouseRightUpEvent(mouseEventArgs);
        //    }

        //    if (state.MiddleButton == MouseState::PressedButton)
        //    {
        //        if (lastState.MiddleButton == MouseState::ReleasedButton)
        //            currentWindow->RaiseMouseMiddleDownEvent(mouseEventArgs);
        //    }
        //    else
        //    {
        //        if (lastState.MiddleButton == MouseState::PressedButton)
        //            currentWindow->RaiseMouseMiddleUpEvent(mouseEventArgs);
        //    }
        //}

        //lastWindow = currentWindow;
        //lastState = state;
    }

    void UIMouseEventDispatcher::SetDomain(UIDomain* value)
    {
        if (domain != value)
        {
            domain = value;
            lastTargetWindow.Reset();
            lastMouseState = MouseState::Empty;
        }
    }

    void UIMouseEventDispatcher::SetDevice(Mouse* value)
    {
        if (device != value)
        {
            device = value;
            lastTargetWindow.Reset();
            lastMouseState = MouseState::Empty;
        }
    }

    IUpdateable* UIMouseEventDispatcher::QueryUpdateableInterface()
    {
        return this;
    }
}
#include <Halak/PCH.h>
#include <Halak/UIMouseEventDispatcher.h>
#include <Halak/UIDomain.h>
#include <Halak/Mouse.h>
#include <Halak/UIMouseButtonEventArgs.h>
#include <Halak/UIMouseEventArgs.h>
#include <Halak/UIMouseWheelEventArgs.h>
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

        UIWindowPtr rootWindow = domain->GetRoot();
        if (rootWindow == nullptr)
            return;

        const MouseState& mouseState = device->GetState();
        UIPickingContext picker(Vector2(mouseState.Position.X, mouseState.Position.Y));

        struct Pick
        {
            static UIWindow* Do(UIPickingContext& context, UIWindow* rootWindow)
            {
                if (context.Pick(rootWindow))
                {
                    if (context.GetResult()->IsWindow())
                        return static_cast<UIWindow*>(context.GetResult());
                    else
                        return context.GetResult()->GetParent();
                }
                else
                    return rootWindow;
            }
        };

        UIWindowPtr pickedWindow = nullptr;
        UIWindowPtr targetWindow = nullptr;

        if (capturedWindow)
            targetWindow = capturedWindow;
        else
        {
            pickedWindow = Pick::Do(picker, rootWindow);
            targetWindow = pickedWindow;
        }

        const UIMouseEventArgs baseArgs = UIMouseEventArgs(targetWindow,
                                                           mouseState.Position,
                                                           mouseState.IsLeftButtonPressed,
                                                           mouseState.IsRightButtonPressed,
                                                           mouseState.IsMiddleButtonPressed);

        if (targetWindow != lastTargetWindow)
        {
            // 가리키고 있는 Window가 달라지면,
            // 이전에 가리킨 Window와 그 부모들에게 MouseLeave Event를 발생시키고
            // 현재 가리키고 있는 Window와 그 부모들에게 MouseEnter Event를 발생시킵니다.
            // 물론 두 Window의 공통된 부모들에게는 아무 Event도 발생시키지 않습니다.

            cachedEnterWindows.clear();
            cachedLeaveWindows.clear();

            for (UIWindow* leaveWindow = lastTargetWindow; leaveWindow; leaveWindow = leaveWindow->GetParent())
                cachedLeaveWindows.push_back(leaveWindow);
            for (UIWindow* enterWindow = targetWindow; enterWindow; enterWindow = enterWindow->GetParent())
            {
                const WindowVector::const_iterator it = std::find(cachedLeaveWindows.begin(), cachedLeaveWindows.end(), enterWindow);
                if (it == cachedLeaveWindows.end())
                    cachedEnterWindows.push_back(enterWindow);
                else
                {
                    cachedLeaveWindows.resize(it - cachedLeaveWindows.begin());
                    break;
                }
            }

            for (WindowVector::const_iterator it = cachedLeaveWindows.begin(); it != cachedLeaveWindows.end(); it++)
                (*it)->RaiseMouseLeaveEvent(baseArgs);

            for (WindowVector::const_iterator it = cachedEnterWindows.begin(); it != cachedEnterWindows.end(); it++)
                (*it)->RaiseMouseEnterEvent(baseArgs);
        }

        if (targetWindow && lastMouseState.Position != mouseState.Position)
            targetWindow->RaiseMouseMoveEvent(baseArgs);

        if (targetWindow)
        {
            if (mouseState.IsLeftButtonPressed)
            {
                if (lastMouseState.IsLeftButtonPressed)
                    targetWindow->RaiseMouseButtonPressingEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseLeftButton));
                else
                {
                    capturedWindow = targetWindow;
                    domain->SetFocus(targetWindow);
                    targetWindow->RaiseMouseButtonDownEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseLeftButton));
                }
            }
            else
            {
                if (lastMouseState.IsLeftButtonPressed)
                {
                    capturedWindow.Reset();
                    targetWindow->RaiseMouseButtonUpEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseLeftButton));

                    if (pickedWindow == nullptr)
                        pickedWindow = Pick::Do(picker, rootWindow);

                    if (targetWindow == pickedWindow)
                        targetWindow->RaiseMouseClickEvent(baseArgs);
                }
            }

            if (mouseState.IsRightButtonPressed)
            {
                if (lastMouseState.IsRightButtonPressed)
                    targetWindow->RaiseMouseButtonPressingEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseRightButton));
                else
                    targetWindow->RaiseMouseButtonDownEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseRightButton));
            }
            else
            {
                if (lastMouseState.IsRightButtonPressed)
                    targetWindow->RaiseMouseButtonUpEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseRightButton));
            }

            if (mouseState.IsMiddleButtonPressed)
            {
                if (lastMouseState.IsMiddleButtonPressed)
                    targetWindow->RaiseMouseButtonPressingEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseMiddleButton));
                else
                    targetWindow->RaiseMouseButtonDownEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseMiddleButton));
            }
            else
            {
                if (lastMouseState.IsMiddleButtonPressed)
                    targetWindow->RaiseMouseButtonUpEvent(UIMouseButtonEventArgs(baseArgs, Key::MouseMiddleButton));
            }

            const int wheelDelta = mouseState.Wheel - lastMouseState.Wheel;
            if (wheelDelta != 0)
                targetWindow->RaiseMouseWheelEvent(UIMouseWheelEventArgs(baseArgs, wheelDelta));
        }

        lastTargetWindow = targetWindow;
        lastMouseState = mouseState;
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
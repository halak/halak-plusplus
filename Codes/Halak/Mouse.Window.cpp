#include <Halak/PCH.h>
#include <Halak/Mouse.h>
#include <Halak/MouseState.h>
#include <Halak/Window.h>

#if (defined(HALAK_PLATFORM_WINDOWS)))

#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>

    namespace Halak
    {
        const MouseState& Mouse::GetState()
        {
            POINT windowsMousePosition = { 0, 0 };
            ::GetCursorPos(&windowsMousePosition);
            ::ScreenToClient(static_cast<HWND>(window->GetHandle()), &windowsMousePosition);
            state->Position     = Point(windowsMousePosition.x, windowsMousePosition.y);
            state->LeftButton   = GetAsyncKeyState(VK_LBUTTON) ? MouseState::PressedButton : MouseState::ReleasedButton;
            state->RightButton  = GetAsyncKeyState(VK_RBUTTON) ? MouseState::PressedButton : MouseState::ReleasedButton;
            state->MiddleButton = GetAsyncKeyState(VK_MBUTTON) ? MouseState::PressedButton : MouseState::ReleasedButton;
            return *state;
        }

        void Mouse::SetPosition(Point value)
        {
            POINT windowsMousePosition = { value.X, value.Y };
            ::ClientToScreen(static_cast<HWND>(window->GetHandle()), &windowsMousePosition);
            ::SetCursorPos(windowsMousePosition.x, windowsMousePosition.y);
        }
    }

#endif
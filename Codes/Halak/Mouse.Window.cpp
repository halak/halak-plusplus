#include <Halak/PCH.h>
#include <Halak/Mouse.h>
#include <Halak/MouseState.h>
#include <Halak/Window.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

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
            state->IsLeftButtonPressed   = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0x0000;
            state->IsRightButtonPressed  = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0x0000; 
            state->IsMiddleButtonPressed = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0x0000;
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
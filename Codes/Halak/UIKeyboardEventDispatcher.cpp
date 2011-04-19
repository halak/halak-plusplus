#include <Halak/PCH.h>
#include <Halak/UIKeyboardEventDispatcher.h>
#include <Halak/ITargetWindow.h>
#include <Halak/Keyboard.h>
#include <Halak/KeyboardState.h>
#include <Halak/UIKeyboardEventArgs.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIKeyboardEventDispatcher::UIKeyboardEventDispatcher()
        : lastTimestamp(0),
          targetWindow(nullptr),
          device(nullptr)
    {
    }

    UIKeyboardEventDispatcher::~UIKeyboardEventDispatcher()
    {
    }

    void UIKeyboardEventDispatcher::Update(float /*dt*/, uint timestamp)
    {
        if (lastTimestamp == timestamp ||
            targetWindow == nullptr ||
            device == nullptr ||
            GetStatus() != ActiveStatus)
            return;

        lastTimestamp = timestamp;

        const KeyboardState& state = device->GetState();

        UIWindow* target = targetWindow->GetTarget();
        uint code = 0;
        for (int i = 0; i < sizeof(state.Keys) / sizeof(state.Keys[0]); i++)
        {
            const dword lastField    = state.Keys[i];
            const dword currentField = lastState.Keys[i];
            for (int k = 0x80000000; k != 0x00000000; k >>= 1, code++)
            {
                const bool lastDown    = (lastField & k) != 0x00000000;
                const bool currentDown = (currentField & k) != 0x00000000;

                if (lastDown == false && currentDown)
                    target->RaiseKeyDownEvent(UIKeyboardEventArgs(target, static_cast<Key::Code>(code)));
                else if (lastDown && currentDown == false)
                    target->RaiseKeyUpEvent(UIKeyboardEventArgs(target, static_cast<Key::Code>(code)));
            }
        }

        lastState = state;
    }

    void UIKeyboardEventDispatcher::SetTargetWindow(ITargetWindow* value)
    {
        if (targetWindow != value)
        {
            targetWindow = value;
            lastState = KeyboardState::Empty;
        }
    }

    void UIKeyboardEventDispatcher::SetDevice(Keyboard* value)
    {
        if (device != value)
        {
            device = value;
            lastState = KeyboardState::Empty;
        }
    }

    IUpdateable* UIKeyboardEventDispatcher::QueryUpdateableInterface()
    {
        return this;
    }
}
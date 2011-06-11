#include <Halak/PCH.h>
#include <Halak/UIKeyboardEventDispatcher.h>
#include <Halak/Keyboard.h>
#include <Halak/KeyboardState.h>
#include <Halak/UIDomain.h>
#include <Halak/UIKeyboardEventArgs.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIKeyboardEventDispatcher::UIKeyboardEventDispatcher()
        : lastTimestamp(0xFFFFFFFF),
          domain(nullptr),
          device(nullptr),
          lastState(KeyboardState::Empty)
    {
    }

    UIKeyboardEventDispatcher::~UIKeyboardEventDispatcher()
    {
    }

    void UIKeyboardEventDispatcher::Update(float /*dt*/, uint timestamp)
    {
        if (lastTimestamp == timestamp ||
            domain == nullptr ||
            device == nullptr ||
            GetStatus() != ActiveStatus)
            return;

        lastTimestamp = timestamp;

        UIVisual* target = domain->GetFocus();
        if (target == nullptr)
            target = domain->GetRoot();
        if (target == nullptr)
            return;

        const KeyboardState& state = device->GetState();

        uint code = 0;
        for (int i = 0; i < sizeof(state.Keys) / sizeof(state.Keys[0]); i++)
        {
            const dword lastField    = state.Keys[i];
            const dword currentField = lastState.Keys[i];
            for (dword k = 0x80000000; k != 0x00000000; k >>= 1, code++)
            {
                const bool lastDown    = (lastField & k) != 0x00000000;
                const bool currentDown = (currentField & k) != 0x00000000;

                if (currentDown)
                {
                    if (lastDown == false)
                        target->RaiseKeyDownEvent(UIKeyboardEventArgs(target, static_cast<Key::Code>(code)));

                    target->RaiseKeyPressingEvent(UIKeyboardEventArgs(target, static_cast<Key::Code>(code)));
                }
                else
                {
                    if (lastDown)
                        target->RaiseKeyUpEvent(UIKeyboardEventArgs(target, static_cast<Key::Code>(code)));
                }
            }
        }

        lastState = state;
    }

    void UIKeyboardEventDispatcher::SetDomain(UIDomain* value)
    {
        if (domain != value)
        {
            domain = value;
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
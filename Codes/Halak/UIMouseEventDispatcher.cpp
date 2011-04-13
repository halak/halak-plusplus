#include <Halak/PCH.h>
#include <Halak/UIMouseEventDispatcher.h>

namespace Halak
{
    UIMouseEventDispatcher::UIMouseEventDispatcher()
        : device(nullptr),
          lastTimestamp(0xFFFFFFFF)
    {
    }

    UIMouseEventDispatcher::~UIMouseEventDispatcher()
    {
    }

    void UIMouseEventDispatcher::Update(float /*dt*/, uint timestamp)
    {
        if (device == nullptr || lastTimestamp == timestamp)
            return;

        lastTimestamp = timestamp;
    }

    Mouse* UIMouseEventDispatcher::GetDevice() const
    {
        return device;
    }

    void UIMouseEventDispatcher::SetDevice(Mouse* value)
    {
        if (device != value)
        {
            if (device)
            {
            }

            device = value;

            if (device)
            {
            }
        }
    }

    IUpdateable* UIMouseEventDispatcher::AcquireUpdateableInterface()
    {
        return this;
    }
}
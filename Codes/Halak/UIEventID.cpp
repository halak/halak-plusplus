#include <Halak/PCH.h>
#include <Halak/UIEventID.h>

namespace Halak
{
    const String UIEventID::EventNames[ApplicationType] = 
    {
        "Unknown",
        "KeyDown",
        "KeyUp",
        "KeyPressing",
        "MouseEnter",
        "MouseLeave",
        "MouseMove",
        "MouseButtonDown",
        "MouseButtonUp",
        "MouseButtonPressing",
        "MouseWheel",
        "MouseClick",
        "GamePadButtonDown",
        "GamePadButtonUp",
        "GamePadButtonPressing",
        "GamePadTrigger",
        "GamePadThumbstick",
   };

    const UIEventID UIEventID::Unknown(UnknownType);
    const UIEventID UIEventID::KeyDown(KeyDownType);
    const UIEventID UIEventID::KeyUp(KeyUpType);
    const UIEventID UIEventID::KeyPressing(KeyPressingType);
    const UIEventID UIEventID::MouseEnter(MouseEnterType);
    const UIEventID UIEventID::MouseLeave(MouseLeaveType);
    const UIEventID UIEventID::MouseMove(MouseMoveType);
    const UIEventID UIEventID::MouseButtonDown(MouseButtonDownType);
    const UIEventID UIEventID::MouseButtonUp(MouseButtonUpType);
    const UIEventID UIEventID::MouseButtonPressing(MouseButtonPressingType);
    const UIEventID UIEventID::MouseWheel(MouseWheelType);
    const UIEventID UIEventID::MouseClick(MouseClickType);
    const UIEventID UIEventID::GamePadButtonDown(GamePadButtonDownType);
    const UIEventID UIEventID::GamePadButtonUp(GamePadButtonUpType);
    const UIEventID UIEventID::GamePadButtonPressing(GamePadButtonPressingType);
    const UIEventID UIEventID::GamePadTrigger(GamePadTriggerType);
    const UIEventID UIEventID::GamePadThumbstick(GamePadThumbstickType);

    const String& UIEventID::ConvertFromTypeToName(Type type)
    {
        if (type != ApplicationType)
            return EventNames[type];
        else
            return String::Empty;
    }

    UIEventID::Type UIEventID::ConvertFromNameToType(const String& name)
    {
        if (name.IsEmpty() == false)
        {
            for (int i = 0; i < sizeof(EventNames) / sizeof(EventNames[0]); i++)
            {
                if (EventNames[i] == name)
                    return static_cast<Type>(i);
            }
        }

        return UnknownType;
    }
}
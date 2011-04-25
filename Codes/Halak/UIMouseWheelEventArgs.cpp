#include <Halak/PCH.h>
#include <Halak/UIMouseWheelEventArgs.h>

namespace Halak
{
    UIMouseWheelEventArgs::UIMouseWheelEventArgs()
        : UIMouseEventArgs(),
          wheelDelta(0)
    {
    }

    UIMouseWheelEventArgs::UIMouseWheelEventArgs(UIWindow* target, Point position, int wheelDelta)
        : UIMouseEventArgs(target, position),
          wheelDelta(wheelDelta)
    {
    }

    UIMouseWheelEventArgs::UIMouseWheelEventArgs(UIWindow* target, Point position, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed, int wheelDelta)
        : UIMouseEventArgs(target, position, isLeftButtonPressed, isRightButtonPressed, isMiddleButtonPressed),
          wheelDelta(wheelDelta)
    {
    }

    UIMouseWheelEventArgs::UIMouseWheelEventArgs(const UIMouseEventArgs& base, int wheelDelta)
        : UIMouseEventArgs(base),
          wheelDelta(wheelDelta)
    {
    }

    UIMouseWheelEventArgs::UIMouseWheelEventArgs(const UIMouseWheelEventArgs& original)
        : UIMouseEventArgs(original),
          wheelDelta(original.wheelDelta)
    {
    }

    UIMouseWheelEventArgs::~UIMouseWheelEventArgs()
    {
    }
}
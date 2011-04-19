#include <Halak/PCH.h>
#include <Halak/UIMouseEventArgs.h>

namespace Halak
{
    UIMouseEventArgs::UIMouseEventArgs()
        : UIEventArgs(),
          position(Point::Zero),
          wheelDelta(0),
          leftButton(false),
          rightButton(false),
          middleButton(false)
    {
    }

    UIMouseEventArgs::UIMouseEventArgs(UIVisual* target, Point position, int wheelDelta)
        : UIEventArgs(target),
          position(position),
          wheelDelta(wheelDelta),
          leftButton(false),
          rightButton(false),
          middleButton(false)
    {
    }

    UIMouseEventArgs::UIMouseEventArgs(UIVisual* target, Point position, int wheelDelta, bool leftButton, bool rightButton, bool middleButton)
        : UIEventArgs(target),
          position(position),
          wheelDelta(wheelDelta),
          leftButton(leftButton),
          rightButton(rightButton),
          middleButton(middleButton)
    {
    }

    UIMouseEventArgs::UIMouseEventArgs(const UIMouseEventArgs& original)
        : UIEventArgs(original),
          position(original.position),
          wheelDelta(original.wheelDelta),
          leftButton(original.leftButton),
          rightButton(original.rightButton),
          middleButton(original.middleButton)
    {
    }

    UIMouseEventArgs::~UIMouseEventArgs()
    {
    }
}
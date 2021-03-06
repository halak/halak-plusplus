#include <Halak/PCH.h>
#include <Halak/UIMouseButtonEventArgs.h>

namespace Halak
{
    UIMouseButtonEventArgs::UIMouseButtonEventArgs()
        : UIMouseEventArgs(),
          buttonCode(Key::None)
    {
    }

    UIMouseButtonEventArgs::UIMouseButtonEventArgs(UIVisual* target, Point position, Key::Code buttonCode)
        : UIMouseEventArgs(target, position),
          buttonCode(buttonCode)
    {
    }

    UIMouseButtonEventArgs::UIMouseButtonEventArgs(UIVisual* target, Point position, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed, Key::Code buttonCode)
        : UIMouseEventArgs(target, position, isLeftButtonPressed, isRightButtonPressed, isMiddleButtonPressed),
          buttonCode(buttonCode)
    {
    }

    UIMouseButtonEventArgs::UIMouseButtonEventArgs(const UIMouseEventArgs& base, Key::Code buttonCode)
        : UIMouseEventArgs(base),
          buttonCode(buttonCode)
    {
    }

    UIMouseButtonEventArgs::UIMouseButtonEventArgs(const UIMouseButtonEventArgs& original)
        : UIMouseEventArgs(original),
          buttonCode(original.buttonCode)
    {
    }

    UIMouseButtonEventArgs::~UIMouseButtonEventArgs()
    {
    }

    UIMouseButtonEventArgs* UIMouseButtonEventArgs::Clone() const
    {
        return new UIMouseButtonEventArgs(*this);
    }
}
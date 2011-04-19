#include <Halak/PCH.h>
#include <Halak/UIKeyboardEventArgs.h>

namespace Halak
{
    UIKeyboardEventArgs::UIKeyboardEventArgs()
        : UIEventArgs(nullptr),
          keyCode(Key::None)
    {
    }

    UIKeyboardEventArgs::UIKeyboardEventArgs(UIVisual* target, Key::Code keyCode)
        : UIEventArgs(target),
          keyCode(keyCode)
    {
    }

    UIKeyboardEventArgs::~UIKeyboardEventArgs()
    {
    }
}
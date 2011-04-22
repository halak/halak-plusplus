#include <Halak/PCH.h>
#include <Halak/UIEventArgs.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIEventArgs::UIEventArgs()
        : target(nullptr)
    {
    }

    UIEventArgs::UIEventArgs(UIWindow* target)
        : target(target)
    {
    }

    UIEventArgs::UIEventArgs(const UIEventArgs& original)
        : target(original.target)
    {
    }

    UIEventArgs::~UIEventArgs()
    {
    }
}
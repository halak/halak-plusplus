#include <Halak/PCH.h>
#include <Halak/UIEventArgs.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    UIEventArgs::UIEventArgs()
        : target(nullptr)
    {
    }

    UIEventArgs::UIEventArgs(UIVisual* target)
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
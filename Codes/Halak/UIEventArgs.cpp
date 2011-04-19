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

    UIEventArgs::~UIEventArgs()
    {
    }
}
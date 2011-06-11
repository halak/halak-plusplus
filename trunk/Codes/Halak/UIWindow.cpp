#include <Halak/PCH.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIWindow::UIWindow()
    {
    }

    UIWindow::UIWindow(int childrenCapacity)
        : UIPanel(childrenCapacity)
    {
    }

    UIWindow::~UIWindow()
    {
    }
}
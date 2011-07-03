#include <Halak/PCH.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIWindow::UIWindow()
        : fixedSize(Vector2::Zero),
          fixedSizeUsed(false)
    {
    }

    UIWindow::UIWindow(int childrenCapacity)
        : UIPanel(childrenCapacity),
          fixedSize(Vector2::Zero),
          fixedSizeUsed(false)
    {
    }

    UIWindow::~UIWindow()
    {
    }

    Vector2 UIWindow::GetDesiredSize()
    {
        if (GetFixedSizeUsed())
            return GetFixedSize();
        else
            return UIVisual::GetDesiredSize();
    }
}
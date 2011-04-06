#include <Halak/UIFittedFrame.h>

namespace Halak
{
    UIFittedFrame::UIFittedFrame()
    {
    }

    UIFittedFrame::~UIFittedFrame()
    {
    }

    RectangleF UIFittedFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        return RectangleF::Empty;
    }
}
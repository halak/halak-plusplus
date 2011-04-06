#include <Halak/UIFixedFrame.h>

namespace Halak
{
    UIFixedFrame::UIFixedFrame()
    {
    }

    UIFixedFrame::~UIFixedFrame()
    {
    }

    RectangleF UIFixedFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        return RectangleF::Empty;
    }
}
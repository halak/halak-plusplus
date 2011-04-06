#include <Halak/UIAnchoredFrame.h>

namespace Halak
{
    UIAnchoredFrame::UIAnchoredFrame()
    {
    }

    UIAnchoredFrame::~UIAnchoredFrame()
    {
    }

    RectangleF UIAnchoredFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        return RectangleF::Empty;
    }
}
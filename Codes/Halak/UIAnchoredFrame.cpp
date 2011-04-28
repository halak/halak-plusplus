#include <Halak/PCH.h>
#include <Halak/UIAnchoredFrame.h>

namespace Halak
{
    UIAnchoredFrame::UIAnchoredFrame()
    {
    }

    UIAnchoredFrame::~UIAnchoredFrame()
    {
    }

    RectangleF UIAnchoredFrame::ComputeBounds(UIVisual* /*owner*/, UIVisualVisitor& /*visitor*/)
    {
        return RectangleF::Empty;
    }
}
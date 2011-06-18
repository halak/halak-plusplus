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

    RectangleF UIAnchoredFrame::ComputeBounds(UIVisualVisitor& /*visitor*/, Vector2 /*desiredSize*/)
    {
        return RectangleF::Empty;
    }
}
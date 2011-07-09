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

    bool UIAnchoredFrame::Setup(const RectangleF& bounds, const RectangleF& referenceBounds)
    {
        return true;
    }

    RectangleF UIAnchoredFrame::ComputeBounds(UIVisualVisitor& /*visitor*/, Vector2 /*desiredSize*/)
    {
        return RectangleF::Empty;
    }
}
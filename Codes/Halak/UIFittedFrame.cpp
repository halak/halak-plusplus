#include <Halak/PCH.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIVisualVisitor.h>

namespace Halak
{
    UIFittedFramePtr UIFittedFrame::Instance = new UIFittedFrame();

    UIFittedFrame::UIFittedFrame()
    {
    }

    UIFittedFrame::~UIFittedFrame()
    {
    }

    bool UIFittedFrame::Setup(const RectangleF& /*bounds*/, const RectangleF& /*referenceBounds*/)
    {
        return false;
    }

    RectangleF UIFittedFrame::ComputeBounds(UIVisualVisitor& visitor, Vector2 /*desiredSize*/)
    {
        return visitor.GetCurrentBounds();
    }
}
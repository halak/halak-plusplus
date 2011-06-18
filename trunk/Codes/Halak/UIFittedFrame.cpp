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

    RectangleF UIFittedFrame::ComputeBounds(UIVisualVisitor& visitor, Vector2 /*desiredSize*/)
    {
        return visitor.GetCurrentBounds();
    }
}
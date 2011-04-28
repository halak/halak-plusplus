#include <Halak/PCH.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIVisualVisitor.h>

namespace Halak
{
    UIFittedFrame::UIFittedFrame()
    {
    }

    UIFittedFrame::~UIFittedFrame()
    {
    }

    RectangleF UIFittedFrame::ComputeBounds(UIVisual* /*owner*/, UIVisualVisitor& visitor)
    {
        return visitor.GetCurrentBounds();
    }
}
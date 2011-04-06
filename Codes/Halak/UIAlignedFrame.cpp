#include <Halak/UIAlignedFrame.h>

namespace Halak
{
    UIAlignedFrame::UIAlignedFrame()
    {
    }

    UIAlignedFrame::~UIAlignedFrame()
    {
    }

    RectangleF UIAlignedFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        return RectangleF::Empty;
    }
}
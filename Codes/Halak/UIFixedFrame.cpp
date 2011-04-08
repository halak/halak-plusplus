#include <Halak/UIFixedFrame.h>

namespace Halak
{
    UIFixedFrame::UIFixedFrame()
        : UIFrame(),
          rectangle(RectangleF::Empty)
    {
    }

    UIFixedFrame::UIFixedFrame(const RectangleF& rectangle)
        : UIFrame(),
          rectangle(rectangle)
    {
    }

    UIFixedFrame::~UIFixedFrame()
    {
    }

    RectangleF UIFixedFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        return rectangle;
    }
}
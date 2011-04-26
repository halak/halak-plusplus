#include <Halak/PCH.h>
#include <Halak/UISequenceFrame.h>

namespace Halak
{
    UISequenceFrame::UISequenceFrame()
    {
    }

    UISequenceFrame::~UISequenceFrame()
    {
    }

    RectangleF UISequenceFrame::ComputeBounds(UIVisualVisitor& /*visitor*/)
    {
        return RectangleF::Empty;
    }
}
#include <Halak/PCH.h>
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

    RectangleF UIFixedFrame::ComputeBounds(UIVisualVisitor& /*visitor*/)
    {
        return rectangle;
    }

    void UIFixedFrame::Move(Vector2 displacement)
    {
        rectangle.X += displacement.X;
        rectangle.Y += displacement.Y;
    }

    bool UIFixedFrame::IsMovable() const
    {
        return true;
    }

    void UIFixedFrame::Resize(float left, float top, float right, float bottom)
    {
        const float boundsLeft   = rectangle.GetLeft() - left;
        const float boundsTop    = rectangle.GetTop() - top;
        const float boundsRight  = rectangle.GetRight() + right;
        const float boundsBottom = rectangle.GetBottom() + bottom;
        rectangle = RectangleF(boundsLeft, boundsTop, boundsRight - boundsLeft, boundsBottom - boundsTop);
    }

    void UIFixedFrame::ResizeTo(Vector2 size)
    {
        rectangle.Width  = size.X;
        rectangle.Height = size.Y;
    }

    bool UIFixedFrame::IsResizable() const
    {
        return true;
    }
}
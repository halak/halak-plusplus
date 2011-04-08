#include <Halak/UIAlignedFrame.h>

namespace Halak
{
    UIAlignedFrame::UIAlignedFrame()
        : UIFrame(),
          align(LeftTop),
          offset(Vector2::Zero),
          size(Vector2::Zero),
          lastBounds(RectangleF::Empty),
          lastReferenceBounds(RectangleF::Empty),
          boundsChanged(true)
    {
    }

    UIAlignedFrame::UIAlignedFrame(Vector2 offset, Vector2 size)
        : UIFrame(),
          align(LeftTop),
          offset(offset),
          size(size),
          lastBounds(RectangleF::Empty),
          lastReferenceBounds(RectangleF::Empty),
          boundsChanged(true)
    {
    }

    UIAlignedFrame::UIAlignedFrame(Alignment align, Vector2 offset, Vector2 size)
        : UIFrame(),
          align(align),
          offset(offset),
          size(size),
          lastBounds(RectangleF::Empty),
          lastReferenceBounds(RectangleF::Empty),
          boundsChanged(true)
    {
    }

    UIAlignedFrame::~UIAlignedFrame()
    {
    }

    RectangleF UIAlignedFrame::ComputeBounds(UIVisualVisitor& visitor)
    {
        const RectangleF referenceBounds = RectangleF::Empty;
        if (boundsChanged || lastReferenceBounds != referenceBounds)
        {
            RectangleF bounds = RectangleF(0.0f, 0.0f, size.X, size.Y);

            switch (align)
            {
                case LeftTop:
                case LeftBottom:
                case LeftMiddle:
                    bounds.X = referenceBounds.GetLeft() + offset.X;
                    break;
                case RightTop:
                case RightBottom:
                case RightMiddle:
                    bounds.X = referenceBounds.GetRight() - offset.X - bounds.Width;
                    break;
                case CenterTop:
                case CenterBottom:
                case Center:
                    bounds.X = referenceBounds.X + ((referenceBounds.Width - bounds.Width) / 2.0f) + offset.X;
                    break;
            }

            switch (align)
            {
                case LeftTop:
                case RightTop:
                case CenterTop:
                    bounds.Y = referenceBounds.GetTop() + offset.Y;
                    break;
                case LeftBottom:
                case RightBottom:
                case CenterBottom:
                    bounds.Y = referenceBounds.GetBottom() - offset.Y - bounds.Height;
                    break;
                case LeftMiddle:
                case RightMiddle:
                case Center:
                    bounds.Y = referenceBounds.Y + ((referenceBounds.Height - bounds.Height) / 2.0f) + offset.Y;
                    break;
            }

            lastBounds = bounds;
            lastReferenceBounds = referenceBounds;
            boundsChanged = false;
        }

        return lastBounds;
    }

    void UIAlignedFrame::SetAlign(Alignment value)
    {
        if (align != value)
        {
            align = value;
            boundsChanged = true;
        }
    }

    void UIAlignedFrame::SetOffset(Vector2 value)
    {
        if (offset != value)
        {
            offset = value;
            boundsChanged = true;
        }
    }

    void UIAlignedFrame::SetSize(Vector2 value)
    {
        if (size != value)
        {
            size = value;
            boundsChanged = true;
        }
    }
}
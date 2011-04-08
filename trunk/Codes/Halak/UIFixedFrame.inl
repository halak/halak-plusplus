namespace Halak
{
    const RectangleF& UIFixedFrame::GetRectangle() const
    {
        return rectangle;
    }

    void UIFixedFrame::SetRectangle(const RectangleF& value)
    {
        rectangle = value;
    }
}
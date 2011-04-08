namespace Halak
{
    RectangleF::RectangleF()
        : X(0.0f), Y(0.0f), Width(0.0f), Height(0.0f)
    {
    }

    RectangleF::RectangleF(float x, float y, float width, float height)
        : X(x), Y(y), Width(width), Height(height)
    {
    }

    RectangleF::RectangleF(Vector2 leftTop, Vector2 rightBottom)
        : X(leftTop.X),
          Y(leftTop.Y),
          Width(rightBottom.X - leftTop.X),
          Height(rightBottom.Y - leftTop.Y)
    {
    }

    RectangleF::RectangleF(const RectangleF& original)
        : X(original.X), Y(original.Y), Width(original.Width), Height(original.Height)
    {
    }

    float RectangleF::GetLeft() const
    {
        return X;
    }

    float RectangleF::GetTop() const
    {
        return Y;
    }

    float RectangleF::GetRight() const
    {
        return X + Width;
    }

    float RectangleF::GetBottom() const
    {
        return Y + Height;
    }

    Vector2 RectangleF::GetCenter() const
    {
        return Vector2(X + Width / 2.0f, Y + Height / 2.0f);
    }

    void RectangleF::SetLeft(float value)
    {
        const float right = GetRight();

        X = value;
        Width = right - X;
    }

    void RectangleF::SetTop(float value)
    {
        const float bottom = GetBottom();

        Y = value;
        Height = bottom - Y;
    }

    void RectangleF::SetRight(float value)
    {
        Width = value - X;
    }

    void RectangleF::SetBottom(float value)
    {
        Height = value - Y;
    }

    bool RectangleF::Contains(Vector2 p) const
    {
        return GetLeft() <= p.X && p.X <= GetRight() &&
               GetTop()  <= p.Y && p.Y <= GetBottom();
    }

    bool RectangleF::IsEmpty() const
    {
        return Width == 0.0f || Height == 0.0f;
    }

    RectangleF& RectangleF::operator = (const RectangleF& original)
    {
        X      = original.X;
        Y      = original.Y;
        Width  = original.Width;
        Height = original.Height;
        return *this;
    }

    bool RectangleF::operator == (const RectangleF& right) const
    {
        return X == right.X && Y == right.Y && Width == right.Width && Height == right.Height;
    }

    bool RectangleF::operator != (const RectangleF& right) const
    {
        return !operator == (right);
    }
}
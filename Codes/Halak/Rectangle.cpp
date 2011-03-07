#include <Halak/Rectangle.h>
#include <functional>

namespace Halak
{
    Rectangle::Rectangle()
        : X(0), Y(0), Width(0), Height(0)
    {
    }

    Rectangle::Rectangle(int x, int y, int width, int height)
        : X(x), Y(y), Width(width), Height(height)
    {
    }

    Rectangle::Rectangle(Point leftTop, Point rightBottom)
        : X(leftTop.X),
          Y(leftTop.Y),
          Width(rightBottom.X - leftTop.X),
          Height(rightBottom.Y - leftTop.Y)
    {
    }

    Rectangle::Rectangle(const Rectangle& original)
        : X(original.X), Y(original.Y), Width(original.Width), Height(original.Height)
    {
    }

    bool Rectangle::Contains(Point p) const
    {
        return GetLeft() <= p.X && p.X <= GetRight() &&
               GetTop()  <= p.Y && p.Y <= GetBottom();
    }

    Rectangle& Rectangle::operator = (const Rectangle& original)
    {
        X      = original.X;
        Y      = original.Y;
        Width  = original.Width;
        Height = original.Height;
        return *this;
    }

    bool Rectangle::operator == (const Rectangle& right) const
    {
        return X == right.X && Y == right.Y && Width == right.Width && Height == right.Height;
    }

    bool Rectangle::operator != (const Rectangle& right) const
    {
        return !operator == (right);
    }

    Rectangle Rectangle::Union(const Rectangle& a, const Rectangle& b)
    {
        const int minimumLeft   = std::min(a.GetLeft(),   b.GetLeft());
        const int minimumTop    = std::min(a.GetTop(),    b.GetTop());
        const int maximumRight  = std::max(a.GetRight(),  b.GetRight());
        const int maximumBottom = std::max(a.GetBottom(), b.GetBottom());
        return Rectangle(Point(minimumLeft, minimumTop), 
                         Point(maximumRight, maximumBottom));
    }

    const Rectangle Rectangle::Empty = Rectangle(0, 0, 0, 0);
}
#include <Halak/Rectangle.h>
#include <functional>

namespace Halak
{
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
#include <Halak/PCH.h>
#include <Halak/Rectangle.h>
#include <Halak/Math.h>

namespace Halak
{
    Rectangle Rectangle::Union(const Rectangle& a, const Rectangle& b)
    {
        const int minimumLeft   = Math::Min(a.GetLeft(),   b.GetLeft());
        const int minimumTop    = Math::Min(a.GetTop(),    b.GetTop());
        const int maximumRight  = Math::Max(a.GetRight(),  b.GetRight());
        const int maximumBottom = Math::Max(a.GetBottom(), b.GetBottom());
        return Rectangle(Point(minimumLeft, minimumTop), 
                         Point(maximumRight, maximumBottom));
    }

    const Rectangle Rectangle::Empty = Rectangle(0, 0, 0, 0);
}
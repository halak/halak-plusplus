#include <Halak/PCH.h>
#include <Halak/RectangleF.h>
#include <Halak/Math.h>

namespace Halak
{
    RectangleF RectangleF::Union(const RectangleF& a, const RectangleF& b)
    {
        const float minimumLeft   = Math::Min(a.GetLeft(),   b.GetLeft());
        const float minimumTop    = Math::Min(a.GetTop(),    b.GetTop());
        const float maximumRight  = Math::Max(a.GetRight(),  b.GetRight());
        const float maximumBottom = Math::Max(a.GetBottom(), b.GetBottom());
        return RectangleF(Vector2(minimumLeft, minimumTop), 
                          Vector2(maximumRight, maximumBottom));
    }

    const RectangleF RectangleF::Empty = RectangleF(0.0f, 0.0f, 0.0f, 0.0f);
}
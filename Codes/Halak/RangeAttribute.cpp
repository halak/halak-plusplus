#include <Halak/RangeAttribute.h>

namespace Halak
{
    RangeAttribute::RangeAttribute(const Any& minValue, const Any& maxValue)
        : minValue(minValue),
          maxValue(maxValue)
    {
    }

    RangeAttribute::~RangeAttribute()
    {
    }

    const Any& RangeAttribute::GetMinValue() const
    {
        return minValue;
    }

    const Any& RangeAttribute::GetMaxValue() const
    {
        return maxValue;
    }
}
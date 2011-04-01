#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/RangeAttribute.h>

namespace Halak
{
    namespace Toolkit
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
}
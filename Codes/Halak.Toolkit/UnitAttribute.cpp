#include <Halak/UnitAttribute.h>

namespace Halak
{
    UnitAttribute::UnitAttribute(const char* name)
        : name(name)
    {
    }

    UnitAttribute::~UnitAttribute()
    {
    }

    const char* UnitAttribute::GetName() const
    {
        return name;
    }
}
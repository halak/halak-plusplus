#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/UnitAttribute.h>

namespace Halak
{
    namespace Toolkit
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
}
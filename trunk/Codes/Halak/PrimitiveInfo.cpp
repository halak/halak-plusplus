#include <Halak/PCH.h>
#include <Halak/PrimitiveInfo.h>

namespace Halak
{
    PrimitiveInfo::PrimitiveInfo(int allocationSize)
        : TypeInfo(TypeInfo::Primitive, allocationSize)
    {
    }

    PrimitiveInfo::~PrimitiveInfo()
    {
    }
}
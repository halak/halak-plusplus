#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PrimitiveInfo.h>

namespace Halak
{
    namespace Toolkit
    {
        PrimitiveInfo::PrimitiveInfo(int allocationSize)
            : TypeInfo(TypeInfo::Primitive, allocationSize)
        {
        }

        PrimitiveInfo::~PrimitiveInfo()
        {
        }
    }
}
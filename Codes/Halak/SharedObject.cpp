#include <Halak/PCH.h>
#include <Halak/SharedObject.h>
#include <Halak/Internal/ReferenceCount.h>
#include <Halak/PointerCasts.h>

namespace Halak
{
    SharedObject::SharedObject()
        : referenceCount(new ReferenceCount())
    {
    }

    SharedObject::~SharedObject()
    {
    }
}
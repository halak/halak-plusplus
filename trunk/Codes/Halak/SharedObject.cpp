#include <Halak/PCH.h>
#include <Halak/SharedObject.h>
#include <Halak/Internal/SharedObjectLife.h>

namespace Halak
{
    SharedObject::SharedObject()
        : life(0)
    {
    }

    SharedObject::SharedObject(const SharedObject& /*original*/)
        : life(0)
    {
    }

    SharedObject::~SharedObject()
    {
    }
}
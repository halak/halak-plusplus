#include <Halak/PCH.h>
#include <Halak/IClassQueryable.h>

namespace Halak
{
    const void* IClassQueryable::QueryClass(uint32 classID) const
    {
        return const_cast<IClassQueryable*>(this)->QueryClass(classID);
    }
}
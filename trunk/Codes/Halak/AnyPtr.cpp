#include <Halak/PCH.h>
#include <Halak/AnyPtr.h>
#include <Halak/DynamicCast.h>

namespace Halak
{
    const AnyPtr AnyPtr::Null;

    void* AnyPtr::DynamicCastTo(const ClassInfo* toClass) const
    {
        if (storage && storage->PointeeType->IsClass())
            return storage->DynamicCastTo(toClass);
        else
            return nullptr;
    }

    AnyPtr& AnyPtr::operator = (const AnyPtr& right)
    {
        Storage* deletingStorage = storage;
        type    = right.type;
        storage = right.storage ? right.storage->Clone() : nullptr;
        delete deletingStorage;
        return *this;
    }

    bool AnyPtr::operator == (const AnyPtr& right) const
    {
        if (storage == right.storage)
            return true;
        if (type != right.type)
            return false;
        if (storage && right.storage)
            return storage->ToVoidPointer() == right.storage->ToVoidPointer();
        else
            return false;
    }

    bool AnyPtr::operator != (const AnyPtr& right) const
    {
        return !operator == (right);
    }
}
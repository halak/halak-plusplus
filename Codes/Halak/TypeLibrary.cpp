#include <Halak/TypeLibrary.h>
#include <Halak/Assert.h>
#include <Halak/TypeInfo.h>
#include <Halak/Delete.h>
#include <Halak/String.h>
#include <algorithm>

namespace Halak
{
    TypeLibrary::TypeLibrary()
    {
    }

    TypeLibrary::~TypeLibrary()
    {
        typeTable.clear();

        TypeCollection deletingTypes;
        deletingTypes.swap(types);

        for (TypeCollection::iterator it = deletingTypes.begin(); it != deletingTypes.end(); it++)
            delete (*it);
    }

    const TypeInfo* TypeLibrary::GetType(uint id) const
    {
        for (TypeCollection::const_iterator it = types.begin(); it != types.end(); it++)
        {
            if ((*it)->GetID() == id)
                return *it;
        }

        return nullptr;
    }

    const TypeInfo* TypeLibrary::GetType(const char* name) const
    {
        for (TypeCollection::const_iterator it = types.begin(); it != types.end(); it++)
        {
            if (CompareString((*it)->GetName(), name) == 0)
                return *it;
        }

        return nullptr;
    }

    const TypeInfo* TypeLibrary::GetType(const String& name) const
    {
        return GetType(name.CStr());
    }
}
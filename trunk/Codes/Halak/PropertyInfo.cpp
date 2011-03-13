#include <Halak/PropertyInfo.h>
#include <Halak/Assert.h>
#include <Halak/Attribute.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    PropertyInfo::~PropertyInfo()
    {
        DeleteAll(attributes);

        delete getter;
        delete setter;
    }

    void PropertyInfo::Add(const Attribute* item)
    {
        HKAssertDebug(std::find(attributes.begin(), attributes.end(), item) == attributes.end());

        attributes.push_back(item);
    }

    bool PropertyInfo::Remove(const Attribute* item)
    {
        AttributeCollection::iterator it = std::find(attributes.begin(), attributes.end(), item);
        if (it != attributes.end())
        {
            attributes.erase(it);
            return true;
        }
        else
            return false;
    }

    Any PropertyInfo::GetValue(const AnyPtr& instance) const
    {
        if (const void* castedInstance = instance.DynamicCastTo(class_))
            return getter->Call(castedInstance);
        else
            return Any::Missing;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    PropertyInfo::Getter::~Getter()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    PropertyInfo::Setter::~Setter()
    {
    }
}
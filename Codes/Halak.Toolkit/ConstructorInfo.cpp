#include <Halak/PCH.h>
#include <Halak/ConstructorInfo.h>
#include <Halak/Assert.h>
#include <Halak/Attribute.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    ConstructorInfo::ConstructorInfo(const Fields& fields)
        : constructor(fields.constructor),
          class_(fields.class_),
          parameters(fields.parameters)
    {
    }

    ConstructorInfo::~ConstructorInfo()
    {
        DeleteAll(attributes);
        delete constructor;
    }

    void ConstructorInfo::Add(const Attribute* item)
    {
        HKAssertDebug(std::find(attributes.begin(), attributes.end(), item) == attributes.end());

        attributes.push_back(item);
    }

    bool ConstructorInfo::Remove(const Attribute* item)
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

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    ConstructorInfo::Constructor::~Constructor()
    {
    }
}
#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/ConstructorInfo.h>
#include <Halak.Toolkit/Attribute.h>
#include <Halak/Assert.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
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
    }
}
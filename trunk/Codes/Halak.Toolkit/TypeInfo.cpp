#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/TypeInfo.h>
#include <Halak.Toolkit/Attribute.h>
#include <Halak/Assert.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        TypeInfo::TypeInfo(Type type, int allocationSize)
            : id(0),
              namespace_(nullptr),
              name(nullptr),
              allocationSize(allocationSize),
              type(static_cast<byte>(type))
        {
        }

        TypeInfo::~TypeInfo()
        {
            DeleteAll(attributes);
        }

        void TypeInfo::Add(const Attribute* item)
        {
            HKAssertDebug(std::find(attributes.begin(), attributes.end(), item) == attributes.end());

            attributes.push_back(item);
        }

        bool TypeInfo::Remove(const Attribute* item)
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
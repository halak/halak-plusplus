#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/EnumInfo.h>
#include <Halak.Toolkit/Attribute.h>
#include <Halak/Assert.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        EnumInfo::EnumInfo(int allocationSize)
            : TypeInfo(TypeInfo::Enum, allocationSize)
        {
        }

        EnumInfo::~EnumInfo()
        {
            DeleteAll(values);
        }

        void EnumInfo::Add(const char* name, int value)
        {
            values.push_back(new Value(name, value));
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        EnumInfo::Value::Value(const char* name, int value)
            : name(name),
              value(value)
        {
        }

        EnumInfo::Value::~Value()
        {
            DeleteAll(attributes);
        }

        void EnumInfo::Value::Add(const Attribute* item)
        {
            HKAssertDebug(std::find(attributes.begin(), attributes.end(), item) == attributes.end());

            attributes.push_back(item);
        }

        bool EnumInfo::Value::Remove(const Attribute* item)
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
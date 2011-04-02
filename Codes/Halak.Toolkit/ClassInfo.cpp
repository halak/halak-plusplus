#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/ClassInfo.h>
#include <Halak.Toolkit/ConstructorInfo.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak/Assert.h>
#include <Halak/Delete.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        ClassInfo::ClassInfo(int allocationSize)
            : TypeInfo(TypeInfo::Class, allocationSize)
        {
        }

        ClassInfo::~ClassInfo()
        {
            DeleteAll(constructors);
            DeleteAll(properties);
        }

        void ClassInfo::Add(const ClassInfo* item)
        {
            HKAssertDebug(Contains(item, true) == false);
            baseClasses.push_back(item);
        }

        void ClassInfo::Add(const ConstructorInfo* item)
        {
            HKAssertDebug(Contains(item, true) == false);
            constructors.push_back(item);
        }

        void ClassInfo::Add(const PropertyInfo* item)
        {
            HKAssertDebug(Contains(item, true) == false);
            properties.push_back(item);
        }

        bool ClassInfo::Remove(const ClassInfo* item)
        {
            ClassCollection::iterator it = std::find(baseClasses.begin(), baseClasses.end(), item);
            if (it != baseClasses.end())
            {
                baseClasses.erase(it);
                return true;
            }
            else
                return false;
        }

        bool ClassInfo::Remove(const ConstructorInfo* item)
        {
            ConstructorCollection::iterator it = std::find(constructors.begin(), constructors.end(), item);
            if (it != constructors.end())
            {
                constructors.erase(it);
                return true;
            }
            else
                return false;
        }

        bool ClassInfo::Remove(const PropertyInfo* item)
        {
            PropertyCollection::iterator it = std::find(properties.begin(), properties.end(), item);
            if (it != properties.end())
            {
                properties.erase(it);
                return true;
            }
            else
                return false;
        }

        bool ClassInfo::Contains(const ClassInfo* item, bool inherits) const
        {
            if (std::find(baseClasses.begin(), baseClasses.end(), item) != baseClasses.end())
                return true;
            else
            {
                if (inherits)
                {
                    for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
                    {
                        if ((*it)->Contains(item, true))
                            return true;
                    }

                    return false;
                }
                else
                    return false;
            }
        }

        bool ClassInfo::Contains(const ConstructorInfo* item, bool inherits) const
        {
            if (std::find(constructors.begin(), constructors.end(), item) != constructors.end())
                return true;
            else
            {
                if (inherits)
                {
                    for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
                    {
                        if ((*it)->Contains(item, true))
                            return true;
                    }

                    return false;
                }
                else
                    return false;
            }
        }

        bool ClassInfo::Contains(const PropertyInfo* item, bool inherits) const
        {
            if (std::find(properties.begin(), properties.end(), item) != properties.end())
                return true;
            else
            {
                if (inherits)
                {
                    for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
                    {
                        if ((*it)->Contains(item, true))
                            return true;
                    }

                    return false;
                }
                else
                    return false;
            }
        }

        const PropertyInfo* ClassInfo::GetProperty(uint id, bool inherits) const
        {
            const PropertyCollection& properties = GetProperties();
            for (PropertyCollection::const_iterator it = properties.begin(); it != properties.end(); it++)
            {
                if ((*it)->GetID() == id)
                    return *it;
            }

            if (inherits)
            {
                for (ClassCollection::const_reverse_iterator it = baseClasses.rbegin(); it != baseClasses.rend(); it++)
                {
                    if (const PropertyInfo* found = GetProperty(id, true))
                        return found;
                }
            }

            return nullptr;
        }

        const PropertyInfo* ClassInfo::GetProperty(const String& name, bool inherits) const
        {
            const PropertyCollection& properties = GetProperties();
            for (PropertyCollection::const_iterator it = properties.begin(); it != properties.end(); it++)
            {
                if ((*it)->GetName() == name)
                    return *it;
            }

            if (inherits)
            {
                for (ClassCollection::const_reverse_iterator it = baseClasses.rbegin(); it != baseClasses.rend(); it++)
                {
                    if (const PropertyInfo* found = GetProperty(name, true))
                        return found;
                }
            }

            return nullptr;
        }

        ClassInfo::AttributeCollection ClassInfo::GetAllAttributes() const
        {
            AttributeCollection result;
            GetAllAttributes(result);
            return result;
        }

        void ClassInfo::GetAllAttributes(AttributeCollection& items) const
        {
            for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
            {
                (*it)->GetAllAttributes(items);
            }

            const AttributeCollection& attributes = GetAttributes();
            for (AttributeCollection::const_iterator it = attributes.begin(); it != attributes.end(); it++)
            {
                HKAssertDebug(std::find(items.begin(), items.end(), *it) == items.end());

                items.push_back(*it);
            }
        }

        ClassInfo::PropertyCollection ClassInfo::GetAllProperties() const
        {
            PropertyCollection result;
            GetAllProperties(result);
            return result;
        }

        void ClassInfo::GetAllProperties(PropertyCollection& items) const
        {
            for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
            {
                (*it)->GetAllProperties(items);
            }

            const PropertyCollection& properties = GetProperties();

            struct CheckIntersection
            {
                static bool Do(const PropertyCollection& a, const PropertyCollection& b)
                {
                    for (PropertyCollection::const_iterator it = a.begin(); it != a.end(); it++)
                    {
                        if (std::find(b.begin(), b.end(), *it) != b.end())
                            return false;
                    }

                    return true;
                }
            };
            HKAssertDebug(CheckIntersection::Do(items, properties) == false);

            items.insert(items.end(), properties.begin(), properties.end());
        }

        int ClassInfo::GetOffset(const ClassInfo* item) const
        {
            if (item == nullptr)
                return -1;
            if (item == this)
                return 0;

            int offset = 0;
            for (ClassCollection::const_iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
            {
                if (item == (*it))
                    return offset;

                const int subOffset = (*it)->GetOffset(item);
                if (subOffset >= 0)
                    return offset + subOffset;
                else
                    offset += (*it)->GetAllocationSize();
            }

            return -1;
        }
    }
}
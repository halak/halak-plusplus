#include <Halak/JSONNodes.h>
#include <Halak/Assert.h>

namespace Halak
{
    JSONNode::JSONNode()
    {
    }
    
    JSONNode::~JSONNode()
    {
    }

    JSONNodeWeakPtr JSONNode::GetParent() const
    {
        return parent;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const String JSONArray::TagName = "JSONArray";

    JSONArray::JSONArray()
    {
    }

    JSONArray::~JSONArray()
    {
    }

    void JSONArray::Add(const Any& value)
    {
        values.push_back(value);
    }

    void JSONArray::RemoveAt(int index)
    {
        HKAssertDebug(0 <= index && index < static_cast<int>(values.size()));
        values.erase(values.begin() + index);
    }

    int JSONArray::GetCount() const
    {
        return static_cast<int>(values.size());
    }

    const Any& JSONArray::GetAt(int index) const
    {
        HKAssertDebug(0 <= index && index < static_cast<int>(values.size()));

        return values[index];
    }

    void JSONArray::SetAt(int index, const Any& value)
    {
        HKAssertDebug(0 <= index && index < static_cast<int>(values.size()));

        values[index] = value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const String JSONObject::TagName = "JSONObject";
    
    JSONObject::JSONObject()
    {
    }

    JSONObject::JSONObject(int capacity)
    {
        members.reserve(capacity);
    }

    JSONObject::~JSONObject()
    {
    }

    JSONObject::MemberCollection::iterator JSONObject::FindIterator(const String& key)
    {
        for (MemberCollection::iterator it = members.begin(); it != members.end(); it++)
        {
            if ((*it).first == key)
                return it;
        }

        return members.end();
    }

    JSONObject::MemberCollection::const_iterator JSONObject::FindIterator(const String& key) const
    {
        for (MemberCollection::const_iterator it = members.begin(); it != members.end(); it++)
        {
            if ((*it).first == key)
                return it;
        }

        return members.end();
    }

    void JSONObject::Add(const String& key, const Any& value)
    {
        MemberCollection::iterator it = FindIterator(key);
        if (it != members.end())
            (*it).second = value;
        else
            members.push_back(Member(key, value));
    }

    bool JSONObject::Remove(const String& key)
    {
        MemberCollection::iterator it = FindIterator(key);
        if (it != members.end())
        {
            members.erase(it);
            return true;
        }
        else
            return false;
    }

    bool JSONObject::Contains(const String& key) const
    {
        return FindIterator(key) != members.end();
    }

    const Any& JSONObject::Find(const String& key) const
    {
        MemberCollection::const_iterator it = FindIterator(key);
        if (it != members.end())
            return (*it).second;
        else
            return Any::Missing;
    }

    const JSONObject::MemberCollection& JSONObject::GetMembers() const
    {
        return members;
    }
}
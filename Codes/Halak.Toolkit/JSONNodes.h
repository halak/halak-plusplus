#pragma once
#ifndef __HALAK_TOOLKIT_JSONOBJECT_H__
#define __HALAK_TOOLKIT_JSONOBJECT_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Any.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class JSONNode : public Asset
            {
                public:
                    JSONNode();
                    virtual ~JSONNode();

                    JSONNodeWeakPtr GetParent() const;

                private:
                    JSONNodeWeakPtr parent;

                    friend class JSONDocument;
            };

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            class JSONArray : public JSONNode
            {
                public:
                    typedef std::vector<Any> ValueCollection;

                    static const String TagName;

                public:
                    JSONArray();
                    virtual ~JSONArray();

                    void Add(const Any& value);
                    void RemoveAt(int index);

                    int GetCount() const;
                    const Any& GetAt(int index) const;
                    void SetAt(int index, const Any& value);

                private:
                    ValueCollection values;
            };

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            class JSONObject : public JSONNode
            {
                public:
                    typedef std::pair<String, Any> Member;
                    typedef std::vector<Member> MemberCollection;

                    static const String TagName;

                public:
                    JSONObject();
                    JSONObject(int capacity);
                    virtual ~JSONObject();

                    void Add(const String& key, const Any& value);
                    bool Remove(const String& key);
                    bool Contains(const String& key) const;
                    const Any& Find(const String& key) const;

                    const MemberCollection& GetMembers() const;

                private:
                    inline MemberCollection::iterator FindIterator(const String& key);
                    inline MemberCollection::const_iterator FindIterator(const String& key) const;

                private:
                    MemberCollection members;
            };
        }
    }

#endif
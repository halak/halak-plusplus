#pragma once
#ifndef __HALAK_TOOLKIT_TYPELIBRARY_H__
#define __HALAK_TOOLKIT_TYPELIBRARY_H__

#   include <Halak.Toolkit/FWD.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class TypeLibrary
            {
                public:
                    typedef std::vector<const TypeInfo*> TypeCollection;

                public:
                    const TypeInfo* Find(uint32 id) const;
                    const TypeInfo* Find(const char* name) const;
                    const TypeInfo* Find(const String& name) const;
                    template <typename T> const TypeInfo* GetTypeInfo();
                    template <typename T> const TypeInfo* GetTypeInfo(T* pointer);

                    inline const TypeCollection& GetItems() const;

                public:
                    static inline TypeLibrary& GetInstance();

                private:
                    TypeLibrary();
                    ~TypeLibrary();

                private:
                    TypeCollection types;
            };
        }
    }

#   include <Halak.Toolkit/TypeLibrary.inl>

#endif
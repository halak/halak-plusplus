#pragma once
#ifndef __HALAK_TYPELIBRARY_H__
#define __HALAK_TYPELIBRARY_H__

#   include <Halak/FWD.h>
#   include <map>
#   include <vector>

    namespace Halak
    {
        class TypeLibrary
        {
            public:
                typedef std::vector<const TypeInfo*> TypeCollection;
                typedef std::map<const char*, const TypeInfo*> TypeDictionary;

            public:               
                const TypeInfo* GetType(uint id) const;
                const TypeInfo* GetType(const char* name) const;
                const TypeInfo* GetType(const String& name) const;
                template <typename T> const TypeInfo* GetType();
                template <typename T> const TypeInfo* GetType(T* pointer);

                inline const TypeCollection& GetTypes() const;

            public:
                static inline TypeLibrary& GetInstance();

            private:
                TypeLibrary();
                ~TypeLibrary();

            private:
                TypeCollection types;
                TypeDictionary typeTable;
        };
    }

#   include <Halak/TypeLibrary.inl>

#endif
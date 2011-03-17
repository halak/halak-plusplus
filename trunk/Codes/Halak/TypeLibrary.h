#pragma once
#ifndef __HALAK_TYPELIBRARY_H__
#define __HALAK_TYPELIBRARY_H__

#   include <Halak/FWD.h>
#   include <vector>

    namespace Halak
    {
        class TypeLibrary
        {
            public:
                typedef std::vector<const TypeInfo*> TypeCollection;

            public:
                const TypeInfo* Find(uint32 id) const;
                const TypeInfo* Find(const char* name) const;
                const TypeInfo* Find(const String& name) const;

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

#   include <Halak/TypeLibrary.inl>

#endif
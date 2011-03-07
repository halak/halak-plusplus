#pragma once
#ifndef __HALAK_TYPEINFO_H__
#define __HALAK_TYPEINFO_H__

#   include <Halak/FWD.h>
#   include <vector>

    namespace Halak
    {
        class TypeInfo
        {
            friend class TypeLibrary;
            friend class PrimitiveRegistrationContext;
            friend class ClassRegistrationContext;
            friend class EnumRegistrationContext;
            public:
                typedef std::vector<const Attribute*> AttributeCollection;

            public:
                void Add(const Attribute* item);
                bool Remove(const Attribute* item);

                inline uint GetID() const;
                inline const char* GetNamespace() const;
                inline const char* GetName() const;
                inline int GetAllocationSize() const;

                inline bool IsPrimitive() const;
                inline bool IsClass() const;
                inline bool IsEnum() const;

                inline const AttributeCollection& GetAttributes() const;

            protected:
                enum Type
                {
                    Primitive = (1 << 0),
                    Class     = (1 << 1),
                    Enum      = (1 << 2),
                };

            protected:
                TypeInfo(Type type, const int allocationSize);
                virtual ~TypeInfo();

            private:
                inline void SetID(uint value);
                inline void SetNamespace(const char* value);
                inline void SetName(const char* value);

            private:
                uint id;
                const char* namespace_;
                const char* name;
                const int allocationSize;
                const byte type;

                AttributeCollection attributes;

            private:
                TypeInfo(const TypeInfo&);
                TypeInfo& operator = (const TypeInfo&);
        };
    }

#   include <Halak/TypeInfo.inl>

#endif
#pragma once
#ifndef __HLAKA_REGISTRATIONCONTEXTS_H__
#define __HLAKA_REGISTRATIONCONTEXTS_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class RegistrationContext
        {
        };

        class ConstructorRegistrationContext : public RegistrationContext
        {
            public:
                ConstructorRegistrationContext(ClassRegistrationContext* parent, ConstructorInfo* constructorInfo);
                ConstructorRegistrationContext(const ConstructorRegistrationContext& original);

                ClassRegistrationContext& Close();

                ConstructorRegistrationContext& Add(Attribute* attribute);

                ConstructorRegistrationContext& operator = (const ConstructorRegistrationContext& right);
                bool operator == (const ConstructorRegistrationContext& right) const;
                bool operator != (const ConstructorRegistrationContext& right) const;

            private:
                ClassRegistrationContext* parent;
                ConstructorInfo* constructorInfo;
        };

        class PropertyRegistrationContext : public RegistrationContext
        {
            public:
                PropertyRegistrationContext(ClassRegistrationContext* parent, PropertyInfo* propertyInfo);
                PropertyRegistrationContext(const PropertyRegistrationContext& original);

                ClassRegistrationContext& Close();

                PropertyRegistrationContext& Add(Attribute* attribute);

                PropertyRegistrationContext& operator = (const PropertyRegistrationContext& right);
                bool operator == (const PropertyRegistrationContext& right) const;
                bool operator != (const PropertyRegistrationContext& right) const;

            private:
                ClassRegistrationContext* parent;
                PropertyInfo* propertyInfo;
        };

        class PrimitiveRegistrationContext : public RegistrationContext
        {
            public:
                typedef PrimitiveInfo TargetType;

            public:
                PrimitiveRegistrationContext(void*, PrimitiveInfo* primitiveInfo);
                PrimitiveRegistrationContext(const PrimitiveRegistrationContext& original);

                void Close();
                
                PrimitiveRegistrationContext& Add(Attribute* attribute);

                PrimitiveRegistrationContext& operator = (const PrimitiveRegistrationContext& right);
                bool operator == (const PrimitiveRegistrationContext& right) const;
                bool operator != (const PrimitiveRegistrationContext& right) const;

            private:
                PrimitiveInfo* primitiveInfo;
        };

        class ClassRegistrationContext : public RegistrationContext
        {
            public:
                typedef ClassInfo TargetType;

            public:
                ClassRegistrationContext(ClassRegistrationContext* parent, ClassInfo* classInfo);
                ClassRegistrationContext(const ClassRegistrationContext& original);

                ClassRegistrationContext& Close();
                
                ClassRegistrationContext& SetID(uint id, const char* namespace_, const char* name);
                template <typename T> ClassRegistrationContext& Inherits();

                ClassRegistrationContext& Add(Attribute* attribute);
                ConstructorRegistrationContext Add(ConstructorInfo* constructorInfo);
                PropertyRegistrationContext Add(PropertyInfo* propertyInfo);

                ClassRegistrationContext& operator = (const ClassRegistrationContext& right);
                bool operator == (const ClassRegistrationContext& right) const;
                bool operator != (const ClassRegistrationContext& right) const;

            public:
                static ClassRegistrationContext Null;

            private:
                ClassRegistrationContext* parent;
                ClassInfo* classInfo;
        };

        class EnumRegistrationContext : public RegistrationContext
        {
            public:
                typedef EnumInfo TargetType;

            public:
                EnumRegistrationContext(ClassRegistrationContext* parent, EnumInfo* enumInfo);
                EnumRegistrationContext(const EnumRegistrationContext& original);

                ClassRegistrationContext& Close();
                
                EnumRegistrationContext& SetID(uint id);
                EnumRegistrationContext& Add(Attribute* attribute);
                EnumRegistrationContext& Add(const char* name, int value);

                EnumRegistrationContext& operator = (const EnumRegistrationContext& right);
                bool operator == (const EnumRegistrationContext& right) const;
                bool operator != (const EnumRegistrationContext& right) const;

            private:
                ClassRegistrationContext* parent;
                EnumInfo* enumInfo;
        };

        template <typename T> inline ClassRegistrationContext Class();
        template <typename T> inline EnumRegistrationContext  Enum();
    }

#   include <Halak/RegistrationContexts.inl>

#endif
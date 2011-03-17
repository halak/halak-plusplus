#pragma once
#ifndef __HALAK_CLASSINFO_H__
#define __HALAK_CLASSINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/TypeInfo.h>
#   include <vector>

    namespace Halak
    {
        class ClassInfo : public TypeInfo
        {
            HKDeclareClassFOURCC('C', 'L', 'I', 'F');
            HKThisIsNoncopyableClass(ClassInfo);
            public:
                typedef std::vector<const ClassInfo*> ClassCollection;
                typedef std::vector<const ConstructorInfo*> ConstructorCollection;
                typedef std::vector<const PropertyInfo*>    PropertyCollection;

            public:
                void Add(const ClassInfo* item);
                void Add(const ConstructorInfo* item);
                void Add(const PropertyInfo* item);
                bool Remove(const ClassInfo* item);
                bool Remove(const ConstructorInfo* item);
                bool Remove(const PropertyInfo* item);
                bool Contains(const ClassInfo* item, bool inherits) const;
                bool Contains(const ConstructorInfo* item, bool inherits) const;
                bool Contains(const PropertyInfo* item, bool inherits) const;

                inline const ClassInfo* GetBaseClass() const;
                inline const ClassCollection& GetBaseClasses() const;
                inline const ConstructorCollection& GetConstructors() const;
                inline const PropertyCollection& GetProperties() const;

                const PropertyInfo* GetProperty(uint id, bool inherits) const;
                const PropertyInfo* GetProperty(const String& name, bool inherits) const;

                AttributeCollection GetAllAttributes() const;
                void                GetAllAttributes(AttributeCollection& items) const;
                PropertyCollection  GetAllProperties() const;
                void                GetAllProperties(PropertyCollection& items) const;

                int GetOffset(const ClassInfo* item) const;

            private:
                ClassInfo(int allocationSize);
                virtual ~ClassInfo();

            private:
                ClassCollection baseClasses;
                ConstructorCollection constructors;
                PropertyCollection  properties;

                friend class TypeLibrary;
        };
    }

#   include <Halak/ClassInfo.inl>

#endif
#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/RegistrationContexts.h>
#include <Halak.Toolkit/ClassInfo.h>
#include <Halak.Toolkit/ConstructorInfo.h>
#include <Halak.Toolkit/EnumInfo.h>
#include <Halak.Toolkit/PrimitiveInfo.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak/Assert.h>

namespace Halak
{
    namespace Toolkit
    {
        ConstructorRegistrationContext::ConstructorRegistrationContext(ClassRegistrationContext* parent, ConstructorInfo* constructorInfo)
            : parent(parent),
              constructorInfo(constructorInfo)
        {
            if (this->parent == nullptr)
                this->parent = &ClassRegistrationContext::Null;
        }

        ConstructorRegistrationContext::ConstructorRegistrationContext(const ConstructorRegistrationContext& original)
            : parent(original.parent),
              constructorInfo(original.constructorInfo)
        {
        }

        ClassRegistrationContext& ConstructorRegistrationContext::Close()
        {
            HKAssertDebug(parent);
            return *parent;
        }

        ConstructorRegistrationContext& ConstructorRegistrationContext::Add(Attribute* attribute)
        {
            constructorInfo->Add(attribute);
            return *this;
        }

        ConstructorRegistrationContext& ConstructorRegistrationContext::operator = (const ConstructorRegistrationContext& right)
        {
            parent = right.parent;
            constructorInfo = right.constructorInfo;
            return *this;
        }
        
        bool ConstructorRegistrationContext::operator == (const ConstructorRegistrationContext& right) const
        {
            return (*parent) == (*right.parent) && constructorInfo == right.constructorInfo;
        }

        bool ConstructorRegistrationContext::operator != (const ConstructorRegistrationContext& right) const
        {
            return !operator == (right);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PropertyRegistrationContext::PropertyRegistrationContext(ClassRegistrationContext* parent, PropertyInfo* propertyInfo)
            : parent(parent),
              propertyInfo(propertyInfo)
        {
            if (this->parent == nullptr)
                this->parent = &ClassRegistrationContext::Null;
        }

        PropertyRegistrationContext::PropertyRegistrationContext(const PropertyRegistrationContext& original)
            : parent(original.parent),
              propertyInfo(original.propertyInfo)
        {
        }

        ClassRegistrationContext& PropertyRegistrationContext::Close()
        {
            HKAssertDebug(parent);
            return *parent;
        }

        PropertyRegistrationContext& PropertyRegistrationContext::Add(Attribute* attribute)
        {
            propertyInfo->Add(attribute);
            return *this;
        }

        PropertyRegistrationContext& PropertyRegistrationContext::operator = (const PropertyRegistrationContext& right)
        {
            parent = right.parent;
            propertyInfo = right.propertyInfo;
            return *this;
        }

        bool PropertyRegistrationContext::operator == (const PropertyRegistrationContext& right) const
        {
            return (*parent) == (*right.parent) && propertyInfo == right.propertyInfo;
        }

        bool PropertyRegistrationContext::operator != (const PropertyRegistrationContext& right) const
        {
            return !operator == (right);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PrimitiveRegistrationContext::PrimitiveRegistrationContext(void*, PrimitiveInfo* primitiveInfo)
            : primitiveInfo(primitiveInfo)
        {
        }

        PrimitiveRegistrationContext::PrimitiveRegistrationContext(const PrimitiveRegistrationContext& original)
            : primitiveInfo(original.primitiveInfo)
        {
        }

        void PrimitiveRegistrationContext::Close()
        {
        }

        PrimitiveRegistrationContext& PrimitiveRegistrationContext::Add(Attribute* attribute)
        {
            primitiveInfo->Add(attribute);
            return *this;
        }

        PrimitiveRegistrationContext& PrimitiveRegistrationContext::operator = (const PrimitiveRegistrationContext& right)
        {
            primitiveInfo = right.primitiveInfo;
            return *this;
        }

        bool PrimitiveRegistrationContext::operator == (const PrimitiveRegistrationContext& right) const
        {
            return primitiveInfo == right.primitiveInfo;
        }

        bool PrimitiveRegistrationContext::operator != (const PrimitiveRegistrationContext& right) const
        {
            return !operator == (right);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        ClassRegistrationContext ClassRegistrationContext::Null = ClassRegistrationContext(nullptr, nullptr);

        ClassRegistrationContext::ClassRegistrationContext(ClassRegistrationContext* parent, ClassInfo* classInfo)
            : parent(parent),
              classInfo(classInfo)
        {
            if (this->parent == nullptr)
                this->parent = &ClassRegistrationContext::Null;
        }

        ClassRegistrationContext::ClassRegistrationContext(const ClassRegistrationContext& original)
            : parent(original.parent),
              classInfo(original.classInfo)
        {
        }

        ClassRegistrationContext& ClassRegistrationContext::Close()
        {
            HKAssertDebug(parent);
            return (*parent);
        }

        ClassRegistrationContext& ClassRegistrationContext::SetID(uint id, const char* namespace_, const char* name)
        {
            classInfo->SetID(id);
            classInfo->SetNamespace(namespace_);
            classInfo->SetName(name);
            return *this;
        }

        ClassRegistrationContext& ClassRegistrationContext::Add(Attribute* attribute)
        {
            static_cast<TypeInfo*>(classInfo)->Add(attribute);
            return *this;
        }

        ConstructorRegistrationContext ClassRegistrationContext::Add(ConstructorInfo* constructorInfo)
        {
            classInfo->Add(constructorInfo);
            return ConstructorRegistrationContext(this, constructorInfo);
        }

        PropertyRegistrationContext ClassRegistrationContext::Add(PropertyInfo* propertyInfo)
        {
            classInfo->Add(propertyInfo);
            return PropertyRegistrationContext(this, propertyInfo);
        }

        ClassRegistrationContext& ClassRegistrationContext::operator = (const ClassRegistrationContext& right)
        {
            parent = right.parent;
            classInfo = right.classInfo;
            return *this;
        }

        bool ClassRegistrationContext::operator == (const ClassRegistrationContext& right) const
        {
            if (parent == &Null && right.parent != &Null)
                return false;
            if (parent != &Null && right.parent == &Null)
                return false;

            return (*parent) == (*right.parent) && classInfo == right.classInfo;
        }

        bool ClassRegistrationContext::operator != (const ClassRegistrationContext& right) const
        {
            return !operator == (right);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        EnumRegistrationContext::EnumRegistrationContext(ClassRegistrationContext* parent, EnumInfo* enumInfo)
            : parent(parent),
              enumInfo(enumInfo)
        {
            if (this->parent == nullptr)
                this->parent = &ClassRegistrationContext::Null;
        }

        EnumRegistrationContext::EnumRegistrationContext(const EnumRegistrationContext& original)
            : parent(original.parent),
              enumInfo(original.enumInfo)
        {
        }

        ClassRegistrationContext& EnumRegistrationContext::Close()
        {
            HKAssertDebug(parent);
            return (*parent);
        }

        EnumRegistrationContext& EnumRegistrationContext::SetID(uint id)
        {
            enumInfo->SetID(id);
            return *this;
        }

        EnumRegistrationContext& EnumRegistrationContext::Add(Attribute* attribute)
        {
            static_cast<TypeInfo*>(enumInfo)->Add(attribute);
            return *this;
        }

        EnumRegistrationContext& EnumRegistrationContext::Add(const char* name, int value)
        {
            enumInfo->Add(name, value);
            return *this;
        }

        EnumRegistrationContext& EnumRegistrationContext::operator = (const EnumRegistrationContext& right)
        {
            parent = right.parent;
            enumInfo = right.enumInfo;
            return *this;
        }

        bool EnumRegistrationContext::operator == (const EnumRegistrationContext& right) const
        {
            return (*parent) == (*right.parent) && enumInfo == right.enumInfo;
        }

        bool EnumRegistrationContext::operator != (const EnumRegistrationContext& right) const
        {
            return !operator == (right);
        }
    }
}
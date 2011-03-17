#ifndef __HALAK_REGISTRATIONCONTEXTS_INL__
#define __HALAK_REGISTRATIONCONTEXTS_INL__

#   include <Halak/Assert.h>
#   include <Halak/ConstructorInfo.h>
#   include <Halak/PropertyInfo.h>
#   include <Halak/TypeLibrary.h>
#   include <Halak/TypeInfo.h>

    namespace Halak
    {
        template <typename T> ClassRegistrationContext& ClassRegistrationContext::Inherits()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().GetType<T>();
            HKAssertDebug(typeInfo && typeInfo->IsClass());
            classInfo->Add(static_cast<const ClassInfo*>(typeInfo));
            return *this;
        }

        template <typename T> ClassRegistrationContext Class()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().GetType<T>();
            HKAssertDebug(typeInfo && typeInfo->IsClass());
            return ClassRegistrationContext(nullptr, const_cast<ClassInfo*>(static_cast<const ClassInfo*>(typeInfo)));
        }

        template <typename T> EnumRegistrationContext Enum()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().GetType<T>();
            HKAssertDebug(typeInfo && typeInfo->IsEnum());
            return ClassRegistrationContext(nullptr, const_cast<EnumInfo*>(static_cast<const EnumInfo*>(typeInfo)));
        }
    }

#endif
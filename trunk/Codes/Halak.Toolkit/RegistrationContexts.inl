#include <Halak.Toolkit/ConstructorInfo.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak.Toolkit/TypeLibrary.h>
#include <Halak.Toolkit/TypeInfo.h>
#include <Halak/Assert.h>

namespace Halak
{
    namespace Toolkit
    {
        template <typename T> ClassRegistrationContext& ClassRegistrationContext::Inherits()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().Find<T>();
            HKAssertDebug(typeInfo && typeInfo->IsClass());
            classInfo->Add(static_cast<const ClassInfo*>(typeInfo));
            return *this;
        }

        template <typename T> ClassRegistrationContext Class()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().Find<T>();
            HKAssertDebug(typeInfo && typeInfo->IsClass());
            return ClassRegistrationContext(nullptr, const_cast<ClassInfo*>(static_cast<const ClassInfo*>(typeInfo)));
        }

        template <typename T> EnumRegistrationContext Enum()
        {
            const TypeInfo* typeInfo = TypeLibrary::GetInstance().Find<T>();
            HKAssertDebug(typeInfo && typeInfo->IsEnum());
            return ClassRegistrationContext(nullptr, const_cast<EnumInfo*>(static_cast<const EnumInfo*>(typeInfo)));
        }
    }
}
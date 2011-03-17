#include <Halak/MPL.h>
#include <Halak/TypeLibrary.h>

namespace Halak
{
    InstanceInfo::InstanceInfo(const TypeInfo* typeInfo)
        : typeInfo(typeInfo),
          fields(0x00)
          
    {
    }

    InstanceInfo::InstanceInfo(const TypeInfo* typeInfo, int pointerDepth)
        : typeInfo(typeInfo),
          fields(ComposeFields(pointerDepth, false))
    {
    }

    InstanceInfo::InstanceInfo(const TypeInfo* typeInfo, bool isReference)
        : typeInfo(typeInfo),
          fields(ComposeFields(0, isReference))
    {
    }

    InstanceInfo::InstanceInfo(const TypeInfo* typeInfo, int pointerDepth, bool isReference)
        : typeInfo(typeInfo),
          fields(ComposeFields(pointerDepth, isReference))
    {
    }

    InstanceInfo::InstanceInfo(const InstanceInfo& original)
        : typeInfo(original.typeInfo),
          fields(original.fields)
    {
    }

    InstanceInfo::~InstanceInfo()
    {
    }

    const TypeInfo* InstanceInfo::GetType() const
    {
        return typeInfo;
    }

    int InstanceInfo::GetPointerDepth() const
    {
        return static_cast<int>(fields & PointerDepthBits);
    }

    bool InstanceInfo::IsReference() const
    {
        return (fields & IsReferenceBit) != 0;
    }

    InstanceInfo& InstanceInfo::operator = (const InstanceInfo& right)
    {
        typeInfo = right.typeInfo;
        fields   = right.fields;
        return *this;
    }

    bool InstanceInfo::operator == (const InstanceInfo& right) const
    {
        return typeInfo == right.typeInfo && fields == right.fields;
    }

    bool InstanceInfo::operator != (const InstanceInfo& right) const
    {
        return !operator == (right);
    }

    template <typename T> InstanceInfo InstanceInfo::From()
    {
        return InstanceInfo(TypeLibrary::GetInstance().Find<T>(), MPL::GetPointerDepth<T>::Value, MPL::IsReference<T>::Value);
    }
}
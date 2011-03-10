#include <Halak/StringFormatterAttribute.h>
#include <Halak/TypeLibrary.h>

namespace Halak
{
    StringFormatterAttribute::StringFormatterAttribute(const char* formatterTypeName)
        : Attribute(),
          formatterTypeName(formatterTypeName)
    {
    }

    StringFormatterAttribute::~StringFormatterAttribute()
    {
    }

    const TypeInfo* StringFormatterAttribute::GetFormatterType() const
    {
        return TypeLibrary::GetInstance().GetType(formatterTypeName);
    }
}
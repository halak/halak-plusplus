#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/StringFormatterAttribute.h>
#include <Halak.Toolkit/TypeLibrary.h>

namespace Halak
{
    namespace Toolkit
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
            return TypeLibrary::GetInstance().Find(formatterTypeName);
        }
    }
}
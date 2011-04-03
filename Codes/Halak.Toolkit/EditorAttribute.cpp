#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/EditorAttribute.h>
#include <Halak.Toolkit/TypeLibrary.h>

namespace Halak
{
    namespace Toolkit
    {
        EditorAttribute::EditorAttribute(const char* editorTypeName)
            : Attribute(),
              editorTypeName(editorTypeName)
        {
        }

        EditorAttribute::~EditorAttribute()
        {
        }

        const TypeInfo* EditorAttribute::GetEditorType() const
        {
            return TypeLibrary::GetInstance().Find(editorTypeName);
        }
    }
}
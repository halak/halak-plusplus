#include <Halak/EditorAttribute.h>
#include <Halak/TypeLibrary.h>

namespace Halak
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
        return TypeLibrary::GetInstance().GetType(editorTypeName);
    }
}
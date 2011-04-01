#pragma once
#ifndef __HALAK_TOOLKIT_EDITORATTRIBUTE_H__
#define __HALAK_TOOLKIT_EDITORATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Attribute.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class EditorAttribute : public Attribute
            {
                public:
                    EditorAttribute(const char* editorTypeName);
                    virtual ~EditorAttribute();

                    const TypeInfo* GetEditorType() const;

                private:
                    const char* editorTypeName;
            };
        }
    }

#endif
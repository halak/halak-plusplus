#pragma once
#ifndef __HALAK_EDITORATTRIBUTE_H__
#define __HALAK_EDITORATTRIBUTE_H__

#   include <Halak/FWD.h>
#   include <Halak/Attribute.h>

    namespace Halak
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

#endif
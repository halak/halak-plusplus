#pragma once
#ifndef __HALAK_TOOLKIT_STRINGFORMATTERATTRIBUTE_H__
#define __HALAK_TOOLKIT_STRINGFORMATTERATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Attribute.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class StringFormatterAttribute : public Attribute
            {
                public:
                    StringFormatterAttribute(const char* formatterTypeName);
                    virtual ~StringFormatterAttribute();

                    const TypeInfo* GetFormatterType() const;

                private:
                    const char* formatterTypeName;
            };
        }
    }

#endif
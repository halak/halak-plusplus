#pragma once
#ifndef __HALAK_STRINGFORMATTERATTRIBUTE_H__
#define __HALAK_STRINGFORMATTERATTRIBUTE_H__

#   include <Halak/FWD.h>
#   include <Halak/Attribute.h>

    namespace Halak
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

#endif
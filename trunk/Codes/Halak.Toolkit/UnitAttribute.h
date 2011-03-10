#pragma once
#ifndef __HALAK_UNITATTRIBUTE_H__
#define __HALAK_UNITATTRIBUTE_H__

#   include <Halak/FWD.h>
#   include <Halak/Attribute.h>

    namespace Halak
    {
        class UnitAttribute : public Attribute
        {
            public:
                UnitAttribute(const char* name);
                virtual ~UnitAttribute();

                const char* GetName() const;

            private:
                const char* name;
        };
    }

#endif
#pragma once
#ifndef __HALAK_TOOLKIT_UNITATTRIBUTE_H__
#define __HALAK_TOOLKIT_UNITATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Attribute.h>

    namespace Halak
    {
        namespace Toolkit
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
    }

#endif
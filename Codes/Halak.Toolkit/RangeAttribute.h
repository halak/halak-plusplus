#pragma once
#ifndef __HALAK_TOOLKIT_RANGEATTRIBUTE_H__
#define __HALAK_TOOLKIT_RANGEATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Attribute.h>
#   include <Halak/Any.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class RangeAttribute : public Attribute
            {
                public:
                    RangeAttribute(const Any& minValue, const Any& maxValue);
                    virtual ~RangeAttribute();

                    const Any& GetMinValue() const;
                    const Any& GetMaxValue() const;

                private:
                    const Any minValue;
                    const Any maxValue;
            };
        }
    }

#endif
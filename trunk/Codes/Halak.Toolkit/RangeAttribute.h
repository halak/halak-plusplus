#pragma once
#ifndef __HALAK_RANGEATTRIBUTE_H__
#define __HALAK_RANGEATTRIBUTE_H__

#   include <Halak/FWD.h>
#   include <Halak/Attribute.h>
#   include <Halak/Any.h>

    namespace Halak
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

#endif
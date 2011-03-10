#pragma once
#ifndef __HALAK_CLONEABLE_INTERFACE__
#define __HALAK_CLONEABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ICloneable
        {
            public:
                static const uint ClassID = 0x00000000;

            public:
                virtual ~ICloneable() { }

                virtual ICloneable* Clone() const;
                virtual ICloneable* CloneWith(CloningContext& context) const = 0;

            protected:
                ICloneable();
                ICloneable(CloningContext& context);
        };
    }

#endif
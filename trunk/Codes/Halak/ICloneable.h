#pragma once
#ifndef __HALAK_CLONEABLE_INTERFACE__
#define __HALAK_CLONEABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ICloneable
        {
            HKDeclareClassFOURCC('I', 'C', 'L', 'N');
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
#pragma once
#ifndef __HALAK_TOOLKIT_ATTRIBUTE_H__
#define __HALAK_TOOLKIT_ATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class Attribute
            {
                HKThisIsNoncopyableClass(Attribute);
                public:
                    virtual ~Attribute();

                protected:
                    Attribute();
            };
        }
    }

#endif
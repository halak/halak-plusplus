#pragma once
#ifndef __HALAK_ATTRIBUTE_H__
#define __HALAK_ATTRIBUTE_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class Attribute
        {
            HKDeclareClassFOURCC('A', 'T', 'T', 'R');
            HKThisIsNoncopyableClass(Attribute);
            public:
                virtual ~Attribute();

            protected:
                Attribute();
        };
    }

#endif
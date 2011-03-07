#pragma once
#ifndef __HALAK_ATTRIBUTE_H__
#define __HALAK_ATTRIBUTE_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class Attribute
        {
            public:
                virtual ~Attribute();

            protected:
                Attribute();

            private:
                Attribute(const Attribute&);
                Attribute& operator = (const Attribute&);
        };
    }

#endif
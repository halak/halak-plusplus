#pragma once
#ifndef __HALAK_OBJECT_H__
#define __HALAK_OBJECT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class Object
        {
            HKDeclareObjectFOURCC('O', 'B', 'J', 'T');
            public:
                virtual ~Object();

            protected:
                Object();
        };
    }

#   include <Halak/Object.inl>

#endif
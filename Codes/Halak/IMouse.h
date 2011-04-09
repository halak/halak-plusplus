#pragma once
#ifndef __HALAK_MOUSE_INTERFACE_H__
#define __HALAK_MOUSE_INTERFACE_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IMouse
        {
            HKClassFOURCC('I', 'M', 'O', 'S');
            public:
                virtual ~IMouse() { }
        };
    }

#endif
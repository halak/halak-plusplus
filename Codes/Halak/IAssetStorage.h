#pragma once
#ifndef __HALAK_ASSETSTORAGE_INTERFACE__
#define __HALAK_ASSETSTORAGE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IAssetStorage
        {
            HKInterfaceFOURCC('I', 'A', 'S', 'S');
            public:
                virtual ~IAssetStorage() { }

                virtual Stream* Open(const URI& uri) = 0;
        };
    }

#endif
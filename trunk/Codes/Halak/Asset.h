#pragma once
#ifndef __HALAK_ASSET_H__
#define __HALAK_ASSET_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>

    namespace Halak
    {
        class Asset : public SharedObject
        {
            HKThisIsNoncopyableClass(Asset);
            public:
                virtual ~Asset();

            protected:
                Asset();
        };
    }

#   include <Halak/Asset.inl>

#endif
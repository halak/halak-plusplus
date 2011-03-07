#pragma once
#ifndef __HALAK_ASSET_H__
#define __HALAK_ASSET_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class Asset : public SharedObject
        {
            public:
                virtual ~Asset();

            protected:
                Asset();

            private:
                Asset(const Asset&);
                Asset& operator = (const Asset&);
        };
    }

#   include <Halak/Asset.inl>

#endif
#pragma once
#ifndef __HALAK_ASSET_H__
#define __HALAK_ASSET_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/URI.h>

    namespace Halak
    {
        class Asset : public SharedObject
        {
            HKThisIsNoncopyableClass(Asset);
            public:
                virtual ~Asset();

                inline const URI& GetURI() const;

            protected:
                Asset();
                Asset(const URI& uri);

            private:
                URI uri;
        };
    }

#   include <Halak/Asset.inl>

#endif
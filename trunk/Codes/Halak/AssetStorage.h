#pragma once
#ifndef __HALAK_ASSETSTORAGE_H__
#define __HALAK_ASSETSTORAGE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IAssetStorage.h>
#   include <vector>

    namespace Halak
    {
        class AssetStorage : public GameComponent, public IAssetStorage
        {
            HKClassFOURCC('A', 'S', 'S', 'T');
            public:
                typedef std::vector<IAssetStorage*> StorageCollection;

            public:
                AssetStorage();
                virtual ~AssetStorage();

                void Add(IAssetStorage* item);
                bool Remove(IAssetStorage* item);

                virtual Stream* Open(const URI& uri);

                inline const StorageCollection& GetSubStorages() const;

                virtual void* QueryClass(uint32 classID);

            private:
                StorageCollection subStorages;
        };
    }

#   include <Halak/AssetStorage.inl>

#endif
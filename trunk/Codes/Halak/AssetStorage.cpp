#include <Halak/AssetStorage.h>
#include <Halak/Assert.h>
#include <algorithm>

namespace Halak
{
    AssetStorage::AssetStorage()
    {
    }

    AssetStorage::~AssetStorage()
    {
    }

    void AssetStorage::Add(IAssetStorage* item)
    {
        HKAssertDebug(std::find(subStorages.begin(), subStorages.end(), item) == subStorages.end());

        subStorages.push_back(item);
    }

    bool AssetStorage::Remove(IAssetStorage* item)
    {
        StorageCollection::iterator it = std::find(subStorages.begin(), subStorages.end(), item);
        if (it != subStorages.end())
        {
            subStorages.erase(it);
            return true;
        }
        else
            return false;
    }

    Stream* AssetStorage::Open(const URI& uri)
    {
        for (StorageCollection::iterator it = subStorages.begin(); it != subStorages.end(); it++)
        {
            if (Stream* stream = (*it)->Open(uri))
                return stream;
        }

        return nullptr;
    }

    void* AssetStorage::QueryClass(uint32 classID)
    {
        switch (classID)
        {
            case IAssetStorage::ClassID:
                return static_cast<IAssetStorage*>(this);
            default:
                return GameComponent::QueryClass(classID);
        }
    }
}
#pragma once
#ifndef __HALAK_ASSETFILESYSTEM_H__
#define __HALAK_ASSETFILESYSTEM_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IAssetStorage.h>

    namespace Halak
    {
        class AssetFileSystem : public GameComponent, public IAssetStorage
        {
            public:
                AssetFileSystem();
                virtual ~AssetFileSystem();

            private:
        };
    }

#endif
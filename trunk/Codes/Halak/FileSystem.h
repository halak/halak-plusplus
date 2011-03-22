#pragma once
#ifndef __HALAK_FILESYSTEM_H__
#define __HALAK_FILESYSTEM_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class FileSystem : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('F', 'S', 'Y', 'S');
            public:
                FileSystem();
                explicit FileSystem(uint id);
                virtual ~FileSystem();
        };
    }

#endif
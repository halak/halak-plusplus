#pragma once
#ifndef __HALAK_FILESYSTEM_H__
#define __HALAK_FILESYSTEM_H__

#   include <Halak/FWD.h>
#   include <windows.h>

    namespace Halak
    {
        class FileSystem
        {
            public:

            public:
                ~FileSystem();

            public:
                static FileSystem Singleton;

            private:
                FileSystem();
        };
    }

#endif
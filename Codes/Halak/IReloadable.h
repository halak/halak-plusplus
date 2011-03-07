#pragma once
#ifndef __HALAK_RELOADABLE_INTERFACE__
#define __HALAK_RELOADABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class IReloadable
        {
            public:
                virtual ~IReloadable() { }

                virtual void Reload() = 0;

                virtual const String& GetFilename() const = 0;
        };
    }

#endif
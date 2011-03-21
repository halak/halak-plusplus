#pragma once
#ifndef __HALAK_REVISABLE_INTERFACE__
#define __HALAK_REVISABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IRevisable
        {
            HKClassIDFOURCC('I', 'R', 'E', 'V');
            public:
                virtual ~IRevisable() { }

                virtual uint GetRevision() const = 0;
        };
    }

#endif
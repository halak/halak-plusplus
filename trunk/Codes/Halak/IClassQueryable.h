#pragma once
#ifndef __HALAK_ICLASSQUERYABLE_H__
#define __HALAK_ICLASSQUERYABLE_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class IClassQueryable
        {
            public:
                virtual ~IClassQueryable() { }

                virtual       void* QueryClass(uint32 classID) = 0;
                virtual const void* QueryClass(uint32 classID) const;
        };
    }

#endif
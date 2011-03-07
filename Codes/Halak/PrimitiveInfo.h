#pragma once
#ifndef __HALAK_PRIMITIVEINFO_H__
#define __HALAK_PRIMITIVEINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/TypeInfo.h>

    namespace Halak
    {
        class PrimitiveInfo : public TypeInfo
        {
            friend class TypeLibrary;
            public:

            private:
                PrimitiveInfo(int allocationSize);
                virtual ~PrimitiveInfo();
        };
    }

#endif
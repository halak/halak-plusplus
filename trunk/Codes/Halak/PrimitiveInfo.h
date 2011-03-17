#pragma once
#ifndef __HALAK_PRIMITIVEINFO_H__
#define __HALAK_PRIMITIVEINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/TypeInfo.h>

    namespace Halak
    {
        class PrimitiveInfo : public TypeInfo
        {
            private:
                PrimitiveInfo(int allocationSize);
                virtual ~PrimitiveInfo();

            private:
                friend class TypeLibrary;
        };
    }

#endif
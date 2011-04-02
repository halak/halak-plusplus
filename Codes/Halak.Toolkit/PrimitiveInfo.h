#pragma once
#ifndef __HALAK_TOOLKIT_PRIMITIVEINFO_H__
#define __HALAK_TOOLKIT_PRIMITIVEINFO_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/TypeInfo.h>

    namespace Halak
    {
        namespace Toolkit
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
    }

#endif
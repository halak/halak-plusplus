#pragma once
#ifndef __HALAK_PRIMITIVETYPES_H__
#define __HALAK_PRIMITIVETYPES_H__

    namespace Halak
    {
        typedef char             int8;
        typedef unsigned char    uint8;
        typedef unsigned char    uchar;
        typedef unsigned char    byte;
        typedef short            int16;
        typedef unsigned short   uint16;
        typedef unsigned short   ushort;
        typedef unsigned short   word;
        typedef int              int32;
        typedef unsigned int     uint32;
        typedef unsigned int     uint;
        typedef unsigned long    ulong;
        typedef unsigned long    dword;
        typedef __int64          int64;
        typedef unsigned __int64 uint64;
        typedef unsigned __int64 qword;

#       ifndef __Out
#       define __Out
#       endif

#       ifndef __InOut
#       define __InOut
#       endif
    }

#endif
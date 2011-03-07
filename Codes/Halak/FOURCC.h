#pragma once
#ifndef __HALAK_FOURCC_H__
#define __HALAK_FOURCC_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
#       define HKMakeFOURCC(a, b, c, d) ((static_cast<uint32>(a) << 24) | \
                                         (static_cast<uint32>(b) << 16) | \
                                         (static_cast<uint32>(c) << 8) | \
                                         (static_cast<uint32>(d) << 0))
    }

#endif
#pragma once
#ifndef __HALAK_ASSERT_H__
#define __HALAK_ASSERT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
#       define HKAssert(exp) if (!(exp)) { Halak::Assert(#exp, __FILE__, __LINE__); }
#       define HKStaticAssert(exp) { char StaticAssertion[(exp) ? 1 : 0]; StaticAssertion; }

#       if (defined(HALAK_DEBUG))
#           define HKAssertDebug(exp) HKAssert(exp)
#       else
#           define HKAssertDebug(exp)
#       endif

        void Assert(const char* expression, const char* filename, int line);
    }

#endif
#pragma once
#ifndef __HALAK_EXCEPTION_H__
#define __HALAK_EXCEPTION_H__

#   include <Halak/FWD.h>
#   include <stdexcept>

    namespace Halak
    {
        class Exception : public std::exception
        {
            public:
                inline Exception(const char* what);
                inline Exception(const Exception& original);

                inline Exception& operator = (const Exception& right);

            private:
        };

#       if (defined(HALAK_EXCEPTION))
#           define HKThrow(condition, exception) { if (condition) { throw exception; } }
#       else
#           define HKThrow(condition, exception) { }
#       endif
    }

#   include <Halak/Exception.inl>

#endif
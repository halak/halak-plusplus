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
                inline Exception();
                inline Exception(const char* what);
                inline Exception(const Exception& original);

                inline Exception& operator = (const Exception& right);

            private:
        };

        class BadCastException : public Exception
        {
            public:
                inline BadCastException();
                inline BadCastException(const char* what);
                inline BadCastException(const BadCastException& original);

                inline BadCastException& operator = (const BadCastException& right);
        };

#       if (defined(HALAK_EXCEPTION))
#           define HKThrow(exception) { throw exception; }
#           define HKIfThrow(condition, exception) { if (condition) { throw exception; } }
#       else
#           define HKThrow(exception) { }
#           define HKIfThrow(condition, exception) { }
#       endif
    }

#   include <Halak/Exception.inl>

#endif
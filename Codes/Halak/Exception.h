#pragma once
#ifndef __HALAK_EXCEPTION_H__
#define __HALAK_EXCEPTION_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class Exception
        {
            public:
                const char* Message;

            public:
                inline Exception();
                inline Exception(const char* message);
                inline Exception(const Exception& original);

                Exception& operator = (const Exception& right);
        };

        class BadArgumentException : public Exception
        {
            public:
                const char* ArgumentName;

            public:
                inline BadArgumentException();
                inline BadArgumentException(const char* argumentName);
                inline BadArgumentException(const char* argumentName, const char* message);
                inline BadArgumentException(const BadArgumentException& original);

                BadArgumentException& operator = (const BadArgumentException& right);
        };

        class BadCastException : public Exception
        {
            public:
                inline BadCastException();
                inline BadCastException(const char* message);
                inline BadCastException(const BadCastException& original);

                BadCastException& operator = (const BadCastException& right);
        };

        class OutOfRangeException : public Exception
        {
            public:
                int Index;
                int Count;

            public:
                inline OutOfRangeException();
                inline OutOfRangeException(const char* message, int index, int count);
                inline OutOfRangeException(const OutOfRangeException& original);

                OutOfRangeException& operator = (const OutOfRangeException& right);
        };

        class NotSupportedException : public Exception
        {
            public:
                inline NotSupportedException();
                inline NotSupportedException(const char* message);
                inline NotSupportedException(const NotSupportedException& original);

                NotSupportedException& operator = (const NotSupportedException& right);
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
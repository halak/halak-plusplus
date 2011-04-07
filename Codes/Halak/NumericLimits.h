#pragma once
#ifndef __HALAK_NUMERICLIMITS_H__
#define __HALAK_NUMERICLIMITS_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class NumericLimits
        {
            HKThisIsStaticClass(NumericLimits);
            public:
                static const char MinChar;
                static const char MaxChar;
                static const uchar MinUChar;
                static const uchar MaxUChar;
                static const short MinShort;
                static const short MaxShort;
                static const ushort MinUShort;
                static const ushort MaxUShort;
                static const int MinInt;
                static const int MaxInt;
                static const uint MinUInt;
                static const uint MaxUInt;
                static const long MinLong;
                static const long MaxLong;
                static const ulong MinULong;
                static const ulong MaxULong;
                static const float MinFloat;
                static const float MaxFloat;
                static const double MinDouble;
                static const double MaxDouble;
                static const int64 MinInt64;
                static const int64 MaxInt64;
                static const uint64 MinUInt64;
                static const uint64 MaxUInt64;

                static const float  FloatNaN;
                static const double DoubleNaN;
        };
    }

#endif
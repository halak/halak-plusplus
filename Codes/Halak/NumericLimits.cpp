#include <Halak/PCH.h>
#include <Halak/NumericLimits.h>
#include <limits>

namespace Halak
{
    const char NumericLimits::MinChar = std::numeric_limits<char>::min();
    const char NumericLimits::MaxChar = std::numeric_limits<char>::max();
    const uchar NumericLimits::MinUChar = std::numeric_limits<uchar>::min();
    const uchar NumericLimits::MaxUChar = std::numeric_limits<uchar>::max();;
    const short NumericLimits::MinShort = std::numeric_limits<short>::min();
    const short NumericLimits::MaxShort = std::numeric_limits<short>::max();;
    const ushort NumericLimits::MinUShort = std::numeric_limits<ushort>::min();
    const ushort NumericLimits::MaxUShort = std::numeric_limits<ushort>::max();;
    const int NumericLimits::MinInt = std::numeric_limits<int>::min();
    const int NumericLimits::MaxInt = std::numeric_limits<int>::max();;
    const uint NumericLimits::MinUInt = std::numeric_limits<uint>::min();
    const uint NumericLimits::MaxUInt = std::numeric_limits<uint>::max();;
    const long NumericLimits::MinLong = std::numeric_limits<long>::min();
    const long NumericLimits::MaxLong = std::numeric_limits<long>::max();;
    const ulong NumericLimits::MinULong = std::numeric_limits<ulong>::min();
    const ulong NumericLimits::MaxULong = std::numeric_limits<ulong>::max();;
    const float NumericLimits::MinFloat = std::numeric_limits<float>::min();
    const float NumericLimits::MaxFloat = std::numeric_limits<float>::max();;
    const double NumericLimits::MinDouble = std::numeric_limits<double>::min();
    const double NumericLimits::MaxDouble = std::numeric_limits<double>::max();;
    const int64 NumericLimits::MinInt64 = std::numeric_limits<int64>::min();
    const int64 NumericLimits::MaxInt64 = std::numeric_limits<int64>::max();;
    const uint64 NumericLimits::MinUInt64 = std::numeric_limits<uint64>::min();
    const uint64 NumericLimits::MaxUInt64 = std::numeric_limits<uint64>::max();

    const float NumericLimits::FloatNaN = std::numeric_limits<float>::quiet_NaN();
    const double NumericLimits::DoubleNaN = std::numeric_limits<double>::quiet_NaN();
}
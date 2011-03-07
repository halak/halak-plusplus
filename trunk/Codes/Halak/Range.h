#ifndef __HALAK_RANGE_H__
#define __HALAK_RANGE_H__

    namespace Halak
    {
        template <typename T> struct Range
        {
            typedef T ElementType;

            T Min;
            T Max;

            inline Range();
            inline Range(T min, T max);
            inline Range(const Range<T>& original);

            inline Range& operator = (const Range& right);
            inline bool operator == (const Range& right) const;
            inline bool operator != (const Range& right) const;
        };
    }

#   include <Halak/Range.inl>

#endif
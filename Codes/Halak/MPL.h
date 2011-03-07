#pragma once
#ifndef __HALAK_MPL_H__
#define __HALAK_MPL_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        namespace MPL
        {
            template <bool C, typename A, typename B> struct If
            {
            };

            template <typename A, typename B> struct If<true,  A, B>
            {
                typedef A Result;
            };

            template <typename A, typename B> struct If<false, A, B>
            {
                typedef B Result;
            };

            template <typename T> struct IsPrimitive
            {
                static const bool Value = false;
            };
            template <> struct IsPrimitive<bool>            { static const bool Value = true; };
            template <> struct IsPrimitive<char>            { static const bool Value = true; };
            template <> struct IsPrimitive<unsigned char>   { static const bool Value = true; };
            template <> struct IsPrimitive<short>           { static const bool Value = true; };
            template <> struct IsPrimitive<unsigned short>  { static const bool Value = true; };
            template <> struct IsPrimitive<int>             { static const bool Value = true; };
            template <> struct IsPrimitive<unsigned int>    { static const bool Value = true; };
            template <> struct IsPrimitive<long>            { static const bool Value = true; };
            template <> struct IsPrimitive<unsigned long>   { static const bool Value = true; };
            template <> struct IsPrimitive<int64>           { static const bool Value = true; };
            template <> struct IsPrimitive<uint64>          { static const bool Value = true; };
            template <> struct IsPrimitive<float>           { static const bool Value = true; };
            template <> struct IsPrimitive<double>          { static const bool Value = true; };

            template <typename T> struct IsReference
            {
                static const bool Value = false;
            };

            template <typename T> struct IsReference<T&>
            {
                static const bool Value = true;
            };

            template <typename T> struct RemoveReference
            {
                typedef T Result;
            };

            template <typename T> struct RemoveReference<T&>
            {
                typedef T Result;
            };

            template <typename T> struct RemoveAllPointers         { typedef T Result; };
            template <typename T> struct RemoveAllPointers<T*>     { typedef T Result; };
            template <typename T> struct RemoveAllPointers<T**>    { typedef T Result; };
            template <typename T> struct RemoveAllPointers<T***>   { typedef T Result; };
            template <typename T> struct RemoveAllPointers<T****>  { typedef T Result; };
            template <typename T> struct RemoveAllPointers<T*****> { typedef T Result; };

            template <typename T> struct GetPointerDepth          { static const unsigned int Value = 0; };
            template <typename T> struct GetPointerDepth<T*>      { static const unsigned int Value = 1; };
            template <typename T> struct GetPointerDepth<T**>     { static const unsigned int Value = 2; };
            template <typename T> struct GetPointerDepth<T***>    { static const unsigned int Value = 3; };
            template <typename T> struct GetPointerDepth<T****>   { static const unsigned int Value = 4; };
            template <typename T> struct GetPointerDepth<T*****>  { static const unsigned int Value = 5; };
            template <typename T> struct GetPointerDepth<T*&>     { static const unsigned int Value = 1; };
            template <typename T> struct GetPointerDepth<T**&>    { static const unsigned int Value = 2; };
            template <typename T> struct GetPointerDepth<T***&>   { static const unsigned int Value = 3; };
            template <typename T> struct GetPointerDepth<T****&>  { static const unsigned int Value = 4; };
            template <typename T> struct GetPointerDepth<T*****&> { static const unsigned int Value = 5; };

            enum { No = 1, Yes = 2 }; 
            typedef char (&NoType)[No]; 
            typedef char (&YesType)[Yes]; 

            struct IntConversionType
            {
                IntConversionType(int);
            };

            NoType  TestIntConversion(...); 
            YesType TestIntConversion(IntConversionType); 

            NoType  TestVolatilePointer(const volatile char *); 
            NoType  TestVolatilePointer(const volatile short *); 
            NoType  TestVolatilePointer(const volatile int *); 
            NoType  TestVolatilePointer(const volatile long *); 
            NoType  TestVolatilePointer(const volatile double *); 
            NoType  TestVolatilePointer(const volatile float *); 
            NoType  TestVolatilePointer(const volatile bool *); 
            YesType TestVolatilePointer(const volatile void *); 

            template <typename T> T* AddPointer(T&); 

            template <bool C> struct BooleanToYesNo
            {
                typedef NoType Result;
            };

            template <> struct BooleanToYesNo<true>
            {
                typedef YesType Result;
            };
        }
    };

#endif
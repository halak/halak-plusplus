#pragma once
#ifndef __HALAK_FWD_H__
#define __HALAK_FWD_H__

#   include <Halak/Classes.h>

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

#       define HKForwardDeclareStruct(name) struct name;
#       define HKForwardDeclareClass(name) class name;
#       define HKForwardDeclareReferenceClass(name) class name; \
                                                    typedef std::tr1::shared_ptr<classname> classname##Ptr; \
                                                    typedef std::tr1::weak_ptr<classname>   classname##WeakPtr;
#       define HKForwardDeclareInterface(name) HKForwardDeclareReferenceClass(name);
#       define HKForwardDeclareTemplateStruct1(arg1, name) template <arg1> struct name;
#       define HKForwardDeclareTemplateClass1(arg1, name) template <arg1> class name;

        HKClasses(HKForwardDeclareStruct, HKForwardDeclareClass, HKForwardDeclareReferenceClass, HKForwardDeclareInterface, HKForwardDeclareTemplateStruct1, HKForwardDeclareTemplateClass1);

        typedef Range<bool>           BoolRange;
        typedef Range<char>           CharRange;
        typedef Range<unsigned char>  UCharRange;
        typedef Range<short>          ShortRange;
        typedef Range<unsigned short> UShortRange;
        typedef Range<int>            IntRange;
        typedef Range<unsigned int>   UIntRange;
        typedef Range<long>           LongRange;
        typedef Range<unsigned long>  ULongRange;
        typedef Range<int64>          Int64Range;
        typedef Range<uint64>         UInt64Range;
        typedef Range<float>          FloatRange;
        typedef Range<double>         DoubleRange;
        typedef Range<Color>          ColorRange;
        typedef Range<Point>          PointRange;
        typedef Range<Quaternion>     QuaternionRange;
        typedef Range<Rectangle>      RectangleRange;
        typedef Range<Vector2>        Vector2Range;
        typedef Range<Vector3>        Vector3Range;
        typedef Range<Vector4>        Vector4Range;

#       undef HKForwardDeclareTemplateClass1
#       undef HKForwardDeclareTemplateStruct1
#       undef HKForwardDeclareInterface
#       undef HKForwardDeclareReferenceClass
#       undef HKForwardDeclareClass
#       undef HKForwardDeclareStruct
    }

#endif
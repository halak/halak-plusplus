#pragma once
#ifndef __HALAK_FOUNDATION_H__
#define __HALAK_FOUNDATION_H__

    namespace Halak
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // BuildConfiguration
#       define HALAK_PLATFORM_WINDOWS
#       define HALAK_EXCEPTION
#       define HALAK_RTTI
#       define HALAK_DEBUG
//#     define HALAK_USE_PRECOMPILEDHEADER

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // PrimitiveTypes
        typedef          char    int8;
        typedef unsigned char    byte;
        typedef unsigned char    uchar;
        typedef unsigned char    uint8;
        typedef          short   int16;
        typedef unsigned short   ushort;
        typedef unsigned short   uint16;
        typedef unsigned short   word;
        typedef          int     int32;
        typedef unsigned int     uint;
        typedef unsigned int     uint32;
        typedef unsigned long    ulong;
        typedef unsigned long    dword;
        typedef          float   real32;
        typedef          double  real64;
        typedef          __int64 int64;
        typedef unsigned __int64 uint64;
        typedef unsigned __int64 qword;

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // FOURCC
#       define HKMakeFOURCC(a, b, c, d) ((static_cast<uint32>(a) << 24) | \
                                         (static_cast<uint32>(b) << 16) | \
                                         (static_cast<uint32>(c) << 8) | \
                                         (static_cast<uint32>(d) << 0))

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // ClassIdioms

        // Static class : static methods로만 이루어져 있고 인스턴스화(Instantiate) 될 수 없는 class를 말합니다.
#       define HKThisIsStaticClass(classname)   private: \
                                                    classname(); \
                                                    classname(const classname&); \
                                                    classname& operator = (const classname&); \
                                                    ~classname();
#       define HKThisIsStaticStruct(classname)  HKThisIsStaticClass(classname) \
                                                public:
#       define HKThisIsNoncopyableClass(classname)  private: \
                                                        classname(const classname&); \
                                                        classname& operator = (const classname&);
#       define HKClassID(id)    public: \
                                    static const uint ClassID = id; \
                                    virtual uint32 GetClassID() const { return ClassID; } \
                                private:
#       define HKClassFOURCC(a, b, c, d) HKClassID(HKMakeFOURCC(a, b, c, d))
#       define HKInterfaceID(id)    public: \
                                        static const uint ClassID = id; \
                                    private:
#       define HKInterfaceFOURCC(a, b, c, d) HKInterfaceID(HKMakeFOURCC(a, b, c, d))
    }

#endif
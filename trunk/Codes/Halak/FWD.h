#pragma once
#ifndef __HALAK_FWD_H__
#define __HALAK_FWD_H__

#   include <Halak/Foundation.h>
#   include <Halak/NullPointer.h>
#   include <Halak/SharedPointer.h>
#   include <Halak/WeakPointer.h>

    namespace Halak
    {
#       define HKForwardDeclareSmartPointerClass(name) class name; \
                                                       typedef SharedPointer<name> name##Ptr; \
                                                       typedef WeakPointer<name>   name##WeakPtr;


        // 01. Foundation
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // (BasicTypes)
                struct Color;
                struct Matrix4;
                struct Point;
                struct Quaternion;
                template <typename T> struct Range;
                struct Ray;
                struct Ray2D;
                struct Rectangle;
                class String;
                struct UUID;
                struct Vector2;
                struct Vector3;
                struct Vector4;
                typedef Range<bool>       BoolRange;
                typedef Range<char>       CharRange;
                typedef Range<uchar>      UCharRange;
                typedef Range<short>      ShortRange;
                typedef Range<ushort>     UShortRange;
                typedef Range<int>        IntRange;
                typedef Range<uint>       UIntRange;
                typedef Range<long>       LongRange;
                typedef Range<ulong>      ULongRange;
                typedef Range<int64>      Int64Range;
                typedef Range<uint64>     UInt64Range;
                typedef Range<float>      FloatRange;
                typedef Range<double>     DoubleRange;
                typedef Range<Color>      ColorRange;
                typedef Range<Point>      PointRange;
                typedef Range<Quaternion> QuaternionRange;
                typedef Range<Rectangle>  RectangleRange;
                typedef Range<Vector2>    Vector2Range;
                typedef Range<Vector3>    Vector3Range;
                typedef Range<Vector4>    Vector4Range;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // (SmartPointers)
                HKForwardDeclareSmartPointerClass(SharedObject);
                template <typename T> class SharedPointer;
                template <typename T> class WeakPointer;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Any
                class Any;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Diagnostics
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Exceptions
                class Exception;
                    class BadCastException;
                    class OutOfRangeException;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // IO
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Mathematics
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Memory
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Time
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Utilities
                class FrameUpdater;
                HKForwardDeclareSmartPointerClass(IRevisable);
                class RectangleStorage;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
        // 02. GameComponent
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // (Structure)
                class GameComponent;
                    class GameModule;
                class GameNode;
                class GameStructure;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Cloning
                class CloningContext;
                HKForwardDeclareSmartPointerClass(ICloneable);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Diagnostics
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Logger
                    class GlobalLogger;
                    class Logger;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Disposal
                class GarbageMan;
                HKForwardDeclareSmartPointerClass(IDisposable);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // FileSystem
                class FileSystem;
                class GlobalFileSystem;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Time
                HKForwardDeclareSmartPointerClass(IUpdateable);
                class Timeline;
                    class ParallelTimeline;
                    class SubTimeline;
            ////////////////////////////////////////////////////////////////////////////////////////////////////

#       undef HKForwardDeclareSmartPointerClass
    }

#endif
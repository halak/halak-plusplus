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

        ////////////////////////////////////////////////////////////////////////////////////////////////////
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
            // Clock
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Diagnostics
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Exceptions
                class Exception;
                    class BadArgumentException;
                    class BadCastException;
                    class OutOfRangeException;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // IO
                class BinaryStreamReader;
                class BinaryStreamWriter;
                class StreamReader;
                class StreamWriter;
                HKForwardDeclareSmartPointerClass(Stream);
                HKForwardDeclareSmartPointerClass(FileStream);
                class FileInfo;
                class DirectoryInfo;
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
                HKForwardDeclareSmartPointerClass(ISpatial);
                HKForwardDeclareSmartPointerClass(ISpatial2D);
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
            // Asset
                class Asset;
                HKForwardDeclareSmartPointerClass(IReloadable);
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
        // 03. (NotYet)
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Graphics
                class DisplaySwapChain;
                class DrawingContext;
                class GraphicsDevice;
                HKForwardDeclareSmartPointerClass(IDrawable);
                class Sprite;
                class SpriteRenderer;
                HKForwardDeclareSmartPointerClass(Texture2D);
                    HKForwardDeclareSmartPointerClass(DynamicTexture2D);
                    HKForwardDeclareSmartPointerClass(MemoryTexture2D);
                    HKForwardDeclareSmartPointerClass(SourceTexture2D);
                class Window;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Input
                class Mouse;
                struct MouseState;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
        // 04. Application
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Animation
                HKForwardDeclareSmartPointerClass(ColorRangeSequence);
                HKForwardDeclareSmartPointerClass(ColorSequence);
                HKForwardDeclareSmartPointerClass(ColorSequence);
                template <typename T> class EvaluableBlenderTemplate;
                HKForwardDeclareSmartPointerClass(EvaluableConstants);
                HKForwardDeclareSmartPointerClass(EvaluableFloatBlender);
                HKForwardDeclareSmartPointerClass(EvaluableFloatConstant);
                HKForwardDeclareSmartPointerClass(EvaluableFloatPrioritySelector);
                HKForwardDeclareSmartPointerClass(EvaluableFloatRangeSequence);
                HKForwardDeclareSmartPointerClass(EvaluableFloatSequence);
                HKForwardDeclareSmartPointerClass(EvaluablePointSequence);
                template <typename T> class EvaluablePrioritySelectorTemplate;
                template <typename T> class EvaluableRangeSequenceTemplate;
                HKForwardDeclareSmartPointerClass(EvaluableSequences);
                template <typename T> class EvaluableSequenceTemplate;
                HKForwardDeclareSmartPointerClass(EvaluableSpriteConstant);
                HKForwardDeclareSmartPointerClass(EvaluableSpriteSequence);
                HKForwardDeclareSmartPointerClass(FloatRangeSequence);
                HKForwardDeclareSmartPointerClass(FloatSequence);
                HKForwardDeclareSmartPointerClass(IBoolEvaluable);
                HKForwardDeclareSmartPointerClass(ICharEvaluable);
                HKForwardDeclareSmartPointerClass(IColorEvaluable);
                HKForwardDeclareSmartPointerClass(IDoubleEvaluable);
                HKForwardDeclareSmartPointerClass(IEvaluables);
                HKForwardDeclareSmartPointerClass(IFloatEvaluable);
                HKForwardDeclareSmartPointerClass(IFloatRangeEvaluable);
                HKForwardDeclareSmartPointerClass(IIntEvaluable);
                HKForwardDeclareSmartPointerClass(ILongEvaluable);
                HKForwardDeclareSmartPointerClass(IPointEvaluable);
                HKForwardDeclareSmartPointerClass(IQuaternionEvaluable);
                HKForwardDeclareSmartPointerClass(IRectangleEvaluable);
                HKForwardDeclareSmartPointerClass(IShortEvaluable);
                HKForwardDeclareSmartPointerClass(ISpriteEvaluable);
                HKForwardDeclareSmartPointerClass(IUCharEvaluable);
                HKForwardDeclareSmartPointerClass(IUIntEvaluable);
                HKForwardDeclareSmartPointerClass(IULongEvaluable);
                HKForwardDeclareSmartPointerClass(IUShortEvaluable);
                HKForwardDeclareSmartPointerClass(IVector2Evaluable);
                HKForwardDeclareSmartPointerClass(IVector3Evaluable);
                HKForwardDeclareSmartPointerClass(IVector4Evaluable);
                HKForwardDeclareSmartPointerClass(PointSequence);
                template <typename T> class SequenceTemplate;
                HKForwardDeclareSmartPointerClass(SpriteSequence);
                HKForwardDeclareSmartPointerClass(Vector2RangeSequence);
                HKForwardDeclareSmartPointerClass(Vector2Sequence);
                HKForwardDeclareSmartPointerClass(Vector3RangeSequence);
                HKForwardDeclareSmartPointerClass(Vector3Sequence);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Collision
                HKForwardDeclareSmartPointerClass(IPickable);
                class PickingContext;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Collision2D
                class CollisionSpace2D;                
                class RaycastReport2D;                
                class Shape2D;
                    class AxisAlignedBoxShape2D;
                    class BoxShape2D;
                    class PointShape2D;
                    class SegmentShape2D;
                    class SphereShape2D;
                    class UserShape2D;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Command
                class Command;
                    class RestorabelCommand;
                        class BatchCommand;
                class CommandHistory;
                class CommandQueue;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Framework
                class GameFramework;
                class GameWindow;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Gameplay
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Entity System
                    HKForwardDeclareSmartPointerClass(Entity);
                        HKForwardDeclareSmartPointerClass(EffectEntity);
                        HKForwardDeclareSmartPointerClass(ParticleEffectEntity);
                    HKForwardDeclareSmartPointerClass(RootEntity);
                    class EntityExtension;
                    class EntityWorld;
                    HKForwardDeclareSmartPointerClass(SpatialNode);
                    HKForwardDeclareSmartPointerClass(SpatialObject);
                    HKForwardDeclareSmartPointerClass(SpatialObject2D);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // JSON
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Lua
                class LuaRuntimeEnvironment;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // OS
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // SFX
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Particle
                class Particle;
                HKForwardDeclareSmartPointerClass(ParticleEmitter);
                HKForwardDeclareSmartPointerClass(ParticleRenderer);
                HKForwardDeclareSmartPointerClass(ParticleSpace);
                class ParticleSpawnPoint;
                class ParticleSpawnSegment;
                class ParticleSpawnBox;
                class ParticleSpawnSphere;
                class SequentialParticle;
                HKForwardDeclareSmartPointerClass(SequentialParticleEmitter);
                class SimpleParticle;
                HKForwardDeclareSmartPointerClass(SimpleParticleEmitter);
                HKForwardDeclareSmartPointerClass(SimpleParticleRenderer);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Script
                HKForwardDeclareSmartPointerClass(Flowchart);
                HKForwardDeclareSmartPointerClass(FlowchartBlock);
                class FlowingContext;
                HKForwardDeclareSmartPointerClass(IFlowchartProcess);
                HKForwardDeclareSmartPointerClass(VariableStorage);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Typography
                HKForwardDeclareSmartPointerClass(Font);
                class FontString;
                class FreeType;
                // (Internal)
                    HKForwardDeclareSmartPointerClass(FreeTypeFontRenderer);
                    struct FreeTypeFontRendererParameters;
                    class Glyph;
                    class GlyphSurface;
                    class GlyphTable;
                ////////////////////////////////////////////////////////////////////////////////////////////////////

#       undef HKForwardDeclareSmartPointerClass
    }

#endif
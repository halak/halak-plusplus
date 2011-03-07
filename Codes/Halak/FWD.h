#pragma once
#ifndef __HALAK_FWD_H__
#define __HALAK_FWD_H__

#   include <Halak/Classes.h>
#   include <Halak/Internal/PrimitiveTypes.h>
#   include <memory>

    namespace Halak
    {
        using std::tr1::enable_shared_from_this;
        using std::tr1::static_pointer_cast;
        using std::tr1::dynamic_pointer_cast;
        using std::tr1::const_pointer_cast;

        using std::tr1::shared_ptr;
        using std::tr1::weak_ptr;

#       define HALAK_PLATFORM_WINDOWS
#       define HALAK_EXCEPTION

#       define HKThisIsStaticClass(classname)   private: \
                                                    classname(); \
                                                    classname(const classname&); \
                                                    classname& operator = (const classname&); \
                                                    ~classname();
#       define HKThisIsNoncopyableClass(classname)  private: \
                                                        classname(const classname&); \
                                                        classname& operator = (const classname&);

#       define HKForwardDeclareSmartPointerClass(classname) class classname; \
                                                            typedef std::tr1::shared_ptr<classname> classname##Ptr; \
                                                            typedef std::tr1::weak_ptr<classname>   classname##WeakPtr;

        HKForwardDeclareSmartPointerClass(SharedObject);

        class  Any;
        class  AnyPtr;
        class  String;
        struct Color;
        struct Matrix4;
        struct Point;
        struct Quaternion;
        struct Ray;
        struct Ray2D;
        struct Rectangle;
        struct UUID;
        struct Vector2;
        struct Vector3;
        struct Vector4;
        template <typename T> struct  Range;
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

        class Clock;
        class Math;
        class RectangleStorage;

        class GameComponent;
            class GameModule;
            class ParallelTimeline;
            class Timeline;
        class GameFramework;
        class GameNode;
        class GameStructure;

        HKForwardDeclareSmartPointerClass(Asset);
        HKForwardDeclareSmartPointerClass(AssetLoader);

        class CloningContext;
        class Timeline;
        HKForwardDeclareSmartPointerClass(ICloneable);
        HKForwardDeclareSmartPointerClass(IDisposable);
        HKForwardDeclareSmartPointerClass(IUpdateable);
        HKForwardDeclareSmartPointerClass(IRevisable);
        HKForwardDeclareSmartPointerClass(ISpatial);
        HKForwardDeclareSmartPointerClass(ISpatial2D);

        class Window;
            class GameWindow;

        HKForwardDeclareSmartPointerClass(IBoolEvaluable);
        HKForwardDeclareSmartPointerClass(ICharEvaluable);
        HKForwardDeclareSmartPointerClass(IColorEvaluable);
        HKForwardDeclareSmartPointerClass(IDoubleEvaluable);
        HKForwardDeclareSmartPointerClass(IFloatEvaluable);
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

        HKForwardDeclareSmartPointerClass(IBoolRangeEvaluable);
        HKForwardDeclareSmartPointerClass(ICharRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IColorRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IDoubleRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IFloatRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IIntRangeEvaluable);
        HKForwardDeclareSmartPointerClass(ILongRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IPointRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IQuaternionRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IRectangleRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IShortRangeEvaluable);
        HKForwardDeclareSmartPointerClass(ISpriteRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IUCharRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IUIntRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IULongRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IUShortRangeEvaluable);
        HKForwardDeclareSmartPointerClass(IVector2RangeEvaluable);
        HKForwardDeclareSmartPointerClass(IVector3RangeEvaluable);
        HKForwardDeclareSmartPointerClass(IVector4RangeEvaluable);

        HKForwardDeclareSmartPointerClass(EvaluableBoolConstant);
        HKForwardDeclareSmartPointerClass(EvaluableCharConstant);
        HKForwardDeclareSmartPointerClass(EvaluableColorConstant);
        HKForwardDeclareSmartPointerClass(EvaluableDoubleConstant);
        HKForwardDeclareSmartPointerClass(EvaluableFloatConstant);
        HKForwardDeclareSmartPointerClass(EvaluableIntConstant);
        HKForwardDeclareSmartPointerClass(EvaluableLongConstant);
        HKForwardDeclareSmartPointerClass(EvaluablePointConstant);
        HKForwardDeclareSmartPointerClass(EvaluableQuaternionConstant);
        HKForwardDeclareSmartPointerClass(EvaluableRectangleConstant);
        HKForwardDeclareSmartPointerClass(EvaluableShortConstant);
        HKForwardDeclareSmartPointerClass(EvaluableSpriteConstant);
        HKForwardDeclareSmartPointerClass(EvaluableUCharConstant);
        HKForwardDeclareSmartPointerClass(EvaluableUIntConstant);
        HKForwardDeclareSmartPointerClass(EvaluableULongConstant);
        HKForwardDeclareSmartPointerClass(EvaluableUShortConstant);
        HKForwardDeclareSmartPointerClass(EvaluableVector2Constant);
        HKForwardDeclareSmartPointerClass(EvaluableVector3Constant);
        HKForwardDeclareSmartPointerClass(EvaluableVector4Constant);

        template <typename T> class SequenceTemplate;
        template <typename T> class EvaluableSequenceTemplate;
        template <typename T> class EvaluableRangeSequenceTemplate;
        HKForwardDeclareSmartPointerClass(BoolSequence);
        HKForwardDeclareSmartPointerClass(CharSequence);
        HKForwardDeclareSmartPointerClass(ColorSequence);
        HKForwardDeclareSmartPointerClass(DoubleSequence);
        HKForwardDeclareSmartPointerClass(FloatSequence);
        HKForwardDeclareSmartPointerClass(IntSequence);
        HKForwardDeclareSmartPointerClass(LongSequence);
        HKForwardDeclareSmartPointerClass(PointSequence);
        HKForwardDeclareSmartPointerClass(QuaternionSequence);
        HKForwardDeclareSmartPointerClass(RectangleSequence);
        HKForwardDeclareSmartPointerClass(ShortSequence);
        HKForwardDeclareSmartPointerClass(SpriteSequence);
        HKForwardDeclareSmartPointerClass(UCharSequence);
        HKForwardDeclareSmartPointerClass(UIntSequence);
        HKForwardDeclareSmartPointerClass(ULongSequence);
        HKForwardDeclareSmartPointerClass(UShortSequence);
        HKForwardDeclareSmartPointerClass(Vector2Sequence);
        HKForwardDeclareSmartPointerClass(Vector3Sequence);
        HKForwardDeclareSmartPointerClass(Vector4Sequence);
        
        HKForwardDeclareSmartPointerClass(BoolRangeSequence);
        HKForwardDeclareSmartPointerClass(CharRangeSequence);
        HKForwardDeclareSmartPointerClass(ColorRangeSequence);
        HKForwardDeclareSmartPointerClass(DoubleRangeSequence);
        HKForwardDeclareSmartPointerClass(FloatRangeSequence);
        HKForwardDeclareSmartPointerClass(IntRangeSequence);
        HKForwardDeclareSmartPointerClass(LongRangeSequence);
        HKForwardDeclareSmartPointerClass(PointRangeSequence);
        HKForwardDeclareSmartPointerClass(QuaternionRangeSequence);
        HKForwardDeclareSmartPointerClass(RectangleRangeSequence);
        HKForwardDeclareSmartPointerClass(ShortRangeSequence);
        HKForwardDeclareSmartPointerClass(SpriteRangeSequence);
        HKForwardDeclareSmartPointerClass(UCharRangeSequence);
        HKForwardDeclareSmartPointerClass(UIntRangeSequence);
        HKForwardDeclareSmartPointerClass(ULongRangeSequence);
        HKForwardDeclareSmartPointerClass(UShortRangeSequence);
        HKForwardDeclareSmartPointerClass(Vector2RangeSequence);
        HKForwardDeclareSmartPointerClass(Vector3RangeSequence);
        HKForwardDeclareSmartPointerClass(Vector4RangeSequence);
        
        HKForwardDeclareSmartPointerClass(EvaluableBoolSequence);
        HKForwardDeclareSmartPointerClass(EvaluableCharSequence);
        HKForwardDeclareSmartPointerClass(EvaluableColorSequence);
        HKForwardDeclareSmartPointerClass(EvaluableDoubleSequence);
        HKForwardDeclareSmartPointerClass(EvaluableFloatSequence);
        HKForwardDeclareSmartPointerClass(EvaluableIntSequence);
        HKForwardDeclareSmartPointerClass(EvaluableLongSequence);
        HKForwardDeclareSmartPointerClass(EvaluablePointSequence);
        HKForwardDeclareSmartPointerClass(EvaluableQuaternionSequence);
        HKForwardDeclareSmartPointerClass(EvaluableRectangleSequence);
        HKForwardDeclareSmartPointerClass(EvaluableShortSequence);
        HKForwardDeclareSmartPointerClass(EvaluableSpriteSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUCharSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUIntSequence);
        HKForwardDeclareSmartPointerClass(EvaluableULongSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUShortSequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector2Sequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector3Sequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector4Sequence);

        HKForwardDeclareSmartPointerClass(EvaluableBoolRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableCharRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableColorRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableDoubleRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableFloatRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableIntRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableLongRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluablePointRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableQuaternionRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableRectangleRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableShortRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUCharRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUIntRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableULongRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableUShortRangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector2RangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector3RangeSequence);
        HKForwardDeclareSmartPointerClass(EvaluableVector4RangeSequence);

        struct PickResult;
        class  PickingContext;
        HKForwardDeclareSmartPointerClass(IPickable);

        class TypeLibrary;
            class Attribute;
                class EditorAttribute;
                class EntityComponentAttribute;
                class RangeAttribute;
                class UnitAttribute;
            class TypeInfo;
                class PrimitiveInfo;
                class ClassInfo;
                class EnumInfo;
            class ConstructorInfo;
            class PropertyInfo;
            class InstanceInfo;
        class PrimitiveRegistrationContext;
        class ClassRegistrationContext;
        class EnumRegistrationContext;
        class ConstructorRegistrationContext;
        class PropertyRegistrationContext;
        class MethodRegistrationContext;
        class FieldRegistrationContext;

        class Mouse;
        struct MouseState;

        class EntityWorld;
        HKForwardDeclareSmartPointerClass(Entity);
            HKForwardDeclareSmartPointerClass(EffectEntity);
                HKForwardDeclareSmartPointerClass(ParticleEffectEntity);
            HKForwardDeclareSmartPointerClass(RootEntity);
        HKForwardDeclareSmartPointerClass(SpatialNode);
        HKForwardDeclareSmartPointerClass(SpatialObject);
        HKForwardDeclareSmartPointerClass(SpatialObject2D);

        HKForwardDeclareSmartPointerClass(Stream);
            HKForwardDeclareSmartPointerClass(FileStream);
        
        class Hotloader;
        HKForwardDeclareSmartPointerClass(IReloadable);

        HKForwardDeclareSmartPointerClass(FileInfo);
        HKForwardDeclareSmartPointerClass(DirectoryInfo);

        HKForwardDeclareSmartPointerClass(JSONDocument);
        HKForwardDeclareSmartPointerClass(JSONNode);
            HKForwardDeclareSmartPointerClass(JSONArray);
            HKForwardDeclareSmartPointerClass(JSONObject);

        class LuaRuntimeEnvironment;

        class DisplaySwapChain;
        class DrawingContext;
        class GraphicsDevice;
        class SpriteRenderer;
        class Sprite;
        HKForwardDeclareSmartPointerClass(Effect);
        HKForwardDeclareSmartPointerClass(IDrawable);
        HKForwardDeclareSmartPointerClass(Texture2D);
            HKForwardDeclareSmartPointerClass(DynamicTexture2D);
            HKForwardDeclareSmartPointerClass(MemoryTexture2D);
            HKForwardDeclareSmartPointerClass(SourceTexture2D);

        class FontString;
        class FreeType;
        HKForwardDeclareSmartPointerClass(Font);

        class TypingContext;
        struct FreeTypeFontRendererParameters;
        HKForwardDeclareSmartPointerClass(FreeTypeFontRenderer);
        HKForwardDeclareSmartPointerClass(Glyph);
        HKForwardDeclareSmartPointerClass(GlyphSurface);
        HKForwardDeclareSmartPointerClass(GlyphTable);
        HKForwardDeclareSmartPointerClass(TypingContext);

        class CommandQueue;
        class CommandHistory;
        class Command;
            class RestorableCommand;
                class BatchCommand;
                class ChangePropertyCommand;

        class Particle;
            class SequentialParticle;
            class SimpleParticle;
        class ParticleController;
        HKForwardDeclareSmartPointerClass(ParticleEmitter);
            HKForwardDeclareSmartPointerClass(SequentialParticleEmitter);
            HKForwardDeclareSmartPointerClass(SimpleParticleEmitter);
        HKForwardDeclareSmartPointerClass(ParticleRenderer);
            HKForwardDeclareSmartPointerClass(SequentialParticleRenderer);
            HKForwardDeclareSmartPointerClass(SimpleParticleRenderer);
        class ParticleSpawnPoint;
            class ParticleSpawnSegment;
            class ParticleSpawnBox;
            class ParticleSpawnSphere;
        class ParticleSpace;

        HKForwardDeclareSmartPointerClass(ISerializable);
        HKForwardDeclareSmartPointerClass(StreamReader);
            HKForwardDeclareSmartPointerClass(BinaryStreamReader);
            HKForwardDeclareSmartPointerClass(JSONStreamReader);
        HKForwardDeclareSmartPointerClass(StreamWriter);
            HKForwardDeclareSmartPointerClass(BinaryStreamWriter);
            HKForwardDeclareSmartPointerClass(JSONStreamWriter);

        HKForwardDeclareSmartPointerClass(Flowchart);
        HKForwardDeclareSmartPointerClass(FlowchartBlock);
        HKForwardDeclareSmartPointerClass(VariableStorage);
        HKForwardDeclareSmartPointerClass(IFlowchartProcess);
        HKForwardDeclareSmartPointerClass(VariableStorage);
        class FlowingContext;

        class SharedObject : public enable_shared_from_this<SharedObject>
        {
            public:
                template <typename T> shared_ptr<T> CastTo()        { return static_pointer_cast<T>(shared_from_this());  }
                template <typename T> shared_ptr<T> DynamicCastTo() { return dynamic_pointer_cast<T>(shared_from_this()); }

            protected:
                SharedObject() { }
                virtual ~SharedObject() { }
        };

        static struct NullPointer
        {
            template <typename T> bool operator == (T* right)            { return right ? false : true; }
            template <typename T> bool operator == (shared_ptr<T> right) { return right.get() ? false : true; }
            template <typename T> bool operator == (weak_ptr<T> right)   { return right.lock().get() ? false : true; }

            template <typename T> bool operator != (T* right)            { return right ? true : false; }
            template <typename T> bool operator != (shared_ptr<T> right) { return right.get() ? true : false; }
            template <typename T> bool operator != (weak_ptr<T> right)   { return right.lock().get() ? true : false; }

            template <typename T> friend bool operator == (T* left, NullPointer)            { return left ? false : true; }
            template <typename T> friend bool operator == (shared_ptr<T> left, NullPointer) { return left.get() ? false : true; }
            template <typename T> friend bool operator == (weak_ptr<T> left, NullPointer)   { return left.lock().get() ? false : true; }

            template <typename T> friend bool operator != (T* left, NullPointer)            { return left ? true : false; }
            template <typename T> friend bool operator != (shared_ptr<T> left, NullPointer) { return left.get() ? true : false; }
            template <typename T> friend bool operator != (weak_ptr<T> left, NullPointer)   { return left.lock().get() ? true : false; }

            template <typename T> operator T* () const            { return 0; }
            template <typename T> operator shared_ptr<T> () const { return shared_ptr<T>(); }
            template <typename T> operator weak_ptr<T> () const   { return weak_ptr<T>(); }
        }nullptr;
    }

#endif
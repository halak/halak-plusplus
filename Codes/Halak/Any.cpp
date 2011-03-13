#include <Halak/Any.h>

namespace Halak
{
    const Any Any::Null = Any();
    const Any Any::Missing = Any(Any::MissingTag());

    Any::Any()
        : type(NullType),
          value(nullptr)
    {
    }

    Any::Any(MissingTag)
        : type(MissingType),
          value(nullptr)
    {
    }

    Any::Any(bool value)
        : type(BooleanType),
          value(reinterpret_cast<void*>(value))          
    {
    }

    Any::Any(char value)
        : type(CharType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(unsigned char value)
        : type(UCharType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(short value)
        : type(ShortType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(unsigned short value)
        : type(UShortType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(int value)
        : type(IntType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(unsigned int value)
        : type(UIntType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(long value)
        : type(LongType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(unsigned long value)
        : type(ULongType),
          value(reinterpret_cast<void*>(value))
    {
    }

    Any::Any(int64 value)
        : type(Int64Type),
          value(reinterpret_cast<void*>(new SmallStorage<int64>(value)))
    {
    }
    
    Any::Any(uint64 value)
        : type(UInt64Type),
          value(reinterpret_cast<void*>(new SmallStorage<uint64>(value)))
    {
    }

    Any::Any(float value)
        : type(FloatType),
          value(reinterpret_cast<void*>(new SmallStorage<float>(value)))
    {
    }

    Any::Any(double value)
        : type(DoubleType),
          value(reinterpret_cast<void*>(new SmallStorage<double>(value)))
    {
    }

    Any::Any(Color value)
        : type(ColorType),
          value(reinterpret_cast<void*>(new SmallStorage<Color>(value)))
    {
    }

    Any::Any(const Matrix4& value)
        : type(Matrix4Type),
          value(reinterpret_cast<void*>(new SmallStorage<Matrix4>(value)))
    {
    }

    Any::Any(Point value)
        : type(PointType),
          value(reinterpret_cast<void*>(new SmallStorage<Point>(value)))
    {
    }

    Any::Any(Quaternion value)
        : type(QuaternionType),
          value(reinterpret_cast<void*>(new SmallStorage<Quaternion>(value)))
    {
    }

    Any::Any(Rectangle value)
        : type(RectangleType),
          value(reinterpret_cast<void*>(new SmallStorage<Rectangle>(value)))
    {
    }

    Any::Any(const char* value)
        : type(value ? StringType : NullType),
          value(value ? reinterpret_cast<void*>(new SmallStorage<String>(value)) : nullptr)
    {
    }

    Any::Any(const String& value)
        : type(StringType),
          value(reinterpret_cast<void*>(new SmallStorage<String>(value)))
    {
    }

    Any::Any(UUID value)
        : type(UUIDType),
          value(reinterpret_cast<void*>(new SmallStorage<UUID>(value)))
    {
    }

    Any::Any(Vector2 value)
        : type(Vector2Type),
          value(reinterpret_cast<void*>(new SmallStorage<Vector2>(value)))
    {
    }

    Any::Any(Vector3 value)
        : type(Vector3Type),
          value(reinterpret_cast<void*>(new SmallStorage<Vector3>(value)))
    {
    }

    Any::Any(Vector4 value)
        : type(Vector4Type),
          value(reinterpret_cast<void*>(new SmallStorage<Vector4>(value)))
    {
    }
    
    Any::Any(const Any& original)
        : value(nullptr),
          type(NullType)
    {
        operator = (original);
    }

    Any::~Any()
    {
        switch (type)
        {
            case Int64Type:
            case UInt64Type:
            case FloatType:
            case DoubleType:
            case ColorType:
            case Matrix4Type:
            case PointType:
            case QuaternionType:
            case RectangleType:
            case StringType:
            case UUIDType:
            case Vector2Type:
            case Vector3Type:
            case Vector4Type:
            case ClassType:
                delete reinterpret_cast<Storage*>(value);
                break;
        }
    }

    const String& Any::GetTag() const
    {
        if (type == ClassType)
            return reinterpret_cast<ClassStorageBase*>(value)->Tag;
        else
            return String::Empty;
    }

    const InstanceInfo& Any::GetStoredInstanceInfo() const
    {
        if (type == ClassType)
            return reinterpret_cast<ClassStorageBase*>(value)->StoredInstanceInfo;
        else
            return InstanceInfo::Empty;
    }

    Any& Any::operator = (const Any& right)
    {
        Type  oldType  = type;
        void* oldValue = value;

        type  = right.type;
        value = nullptr;

        switch (oldType)
        {
            case Int64Type:
            case UInt64Type:
            case FloatType:
            case DoubleType:
            case ColorType:
            case Matrix4Type:
            case PointType:
            case QuaternionType:
            case RectangleType:
            case StringType:
            case UUIDType:
            case Vector2Type:
            case Vector3Type:
            case Vector4Type:
            case ClassType:
                delete reinterpret_cast<Storage*>(oldValue);
                break;
        }

        switch (type)
        {
            case NullType:
            case MissingType:
                value = nullptr;
                break;
            case BooleanType:
            case CharType:
            case UCharType:
            case ShortType:
            case UShortType:
            case IntType:
            case UIntType:
            case LongType:
            case ULongType:
                value = right.value;
                break;
            case Int64Type:
            case UInt64Type:
            case FloatType:
            case DoubleType:
            case ColorType:
            case Matrix4Type:
            case PointType:
            case QuaternionType:
            case RectangleType:
            case StringType:
            case UUIDType:
            case Vector2Type:
            case Vector3Type:
            case Vector4Type:
            case ClassType:
                value = reinterpret_cast<void*>(reinterpret_cast<Storage*>(right.value)->Clone());
                break;
        }

        return *this;
    }

    bool Any::operator == (const Any& right) const
    {
        if (type != right.type)
            return false;

        switch (type)
        {
            case NullType:
            case MissingType:
                return true;
            case BooleanType:
            case CharType:
            case UCharType:
            case ShortType:
            case UShortType:
            case IntType:
            case UIntType:
            case LongType:
            case ULongType:
                return value == right.value;
            case Int64Type:
            case UInt64Type:
            case FloatType:
            case DoubleType:
            case ColorType:
            case Matrix4Type:
            case PointType:
            case QuaternionType:
            case RectangleType:
            case StringType:
            case UUIDType:
            case Vector2Type:
            case Vector3Type:
            case Vector4Type:
            case ClassType:
                return reinterpret_cast<Storage*>(value)->Equals(reinterpret_cast<Storage*>(right.value));
            default:
                return false;
        }
    }

    bool Any::operator != (const Any& right) const
    {
        return !operator == (right);
    }
}
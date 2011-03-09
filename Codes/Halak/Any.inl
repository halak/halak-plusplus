#pragma once
#ifndef __HALAK_ANY_INL__
#define __HALAK_ANY_INL__

#   include <stdexcept>

    namespace Halak
    {
        template <typename T> Any::Any(const T& value)
            : type(ClassType),
              value(reinterpret_cast<void*>(new ClassStorage<T>(value)))
        {
        }

        template <typename T> Any::Any(const T& value, const String& tag)
            : type(ClassType),
              value(reinterpret_cast<void*>(new ClassStorage<T>(value, tag)))
        {
        }

        Any::Type Any::GetType() const
        {
            return type;
        }

        bool Any::GetBoolean() const
        {
            HKAssertDebug(type == BooleanType);
            return reinterpret_cast<bool>(value);
        }

        char Any::GetChar() const
        {
            HKAssertDebug(type == CharType);
            return reinterpret_cast<char>(value);
        }

        unsigned char Any::GetUChar() const
        {
            HKAssertDebug(type == UCharType);
            return reinterpret_cast<unsigned char>(value);
        }

        short Any::GetShort() const
        {
            HKAssertDebug(type == ShortType);
            return reinterpret_cast<short>(value);
        }

        unsigned short Any::GetUShort() const
        {
            HKAssertDebug(type == UShortType);
            return reinterpret_cast<unsigned short>(value);
        }

        int Any::GetInt() const
        {
            HKAssertDebug(type == IntType);
            return reinterpret_cast<int>(value);
        }

        unsigned int Any::GetUInt() const
        {
            HKAssertDebug(type == UIntType);
            return reinterpret_cast<unsigned int>(value);
        }

        long Any::GetLong() const
        {
            HKAssertDebug(type == LongType);
            return reinterpret_cast<long>(value);
        }

        unsigned long Any::GetULong() const
        {
            HKAssertDebug(type == ULongType);
            return reinterpret_cast<unsigned long>(value);
        }

        int64 Any::GetInt64() const
        {
            HKAssertDebug(type == Int64Type);
            return reinterpret_cast<SmallStorage<int64>*>(value)->Value;
        }

        uint64 Any::GetUInt64() const
        {
            HKAssertDebug(type == UInt64Type);
            return reinterpret_cast<SmallStorage<uint64>*>(value)->Value;
        }

        float Any::GetFloat() const
        {
            HKAssertDebug(type == FloatType);
            return reinterpret_cast<SmallStorage<float>*>(value)->Value;
        }

        double Any::GetDouble() const
        {
            HKAssertDebug(type == DoubleType);
            return reinterpret_cast<SmallStorage<double>*>(value)->Value;
        }

        Color Any::GetColor() const
        {
            HKAssertDebug(type == ColorType);
            return reinterpret_cast<SmallStorage<Color>*>(value)->Value;
        }

        const Matrix4& Any::GetMatrix4() const
        {
            HKAssertDebug(type == Matrix4Type);
            return reinterpret_cast<SmallStorage<Matrix4>*>(value)->Value;
        }

        Point Any::GetPoint() const
        {
            HKAssertDebug(type == PointType);
            return reinterpret_cast<SmallStorage<Point>*>(value)->Value;
        }

        Quaternion Any::GetQuaternion() const
        {
            HKAssertDebug(type == QuaternionType);
            return reinterpret_cast<SmallStorage<Quaternion>*>(value)->Value;
        }

        Rectangle Any::GetRectangle() const
        {
            HKAssertDebug(type == RectangleType);
            return reinterpret_cast<SmallStorage<Rectangle>*>(value)->Value;
        }

        const String& Any::GetString() const
        {
            HKAssertDebug(type == StringType);
            return reinterpret_cast<SmallStorage<String>*>(value)->Value;
        }

        UUID Any::GetUUID() const
        {
            HKAssertDebug(type == UUIDType);
            return reinterpret_cast<SmallStorage<UUID>*>(value)->Value;
        }

        Vector2 Any::GetVector2() const
        {
            HKAssertDebug(type == Vector2Type);
            return reinterpret_cast<SmallStorage<Vector2>*>(value)->Value;
        }

        Vector3 Any::GetVector3() const
        {
            HKAssertDebug(type == Vector3Type);
            return reinterpret_cast<SmallStorage<Vector3>*>(value)->Value;
        }

        Vector4 Any::GetVector4() const
        {
            HKAssertDebug(type == Vector4Type);
            return reinterpret_cast<SmallStorage<Vector4>*>(value)->Value;
        }

        template <typename T> T Any::CastNumericValueTo() const
        {
            switch (type)
            {
                case BooleanType:
                    return static_cast<T>(GetBoolean());
                case CharType:
                    return static_cast<T>(GetChar());
                case UCharType:
                    return static_cast<T>(GetUChar());
                case ShortType:
                    return static_cast<T>(GetShort());
                case UShortType:
                    return static_cast<T>(GetUShort());
                case IntType:
                    return static_cast<T>(GetInt());
                case UIntType:
                    return static_cast<T>(GetUInt());
                case LongType:
                    return static_cast<T>(GetLong());
                case ULongType:
                    return static_cast<T>(GetULong());
                case Int64Type:
                    return static_cast<T>(GetInt64());
                case UInt64Type:
                    return static_cast<T>(GetUInt64());
                case FloatType:
                    return static_cast<T>(GetFloat());
                case DoubleType:
                    return static_cast<T>(GetDouble());
                default:
                    throw std::bad_cast();
            }
        }

        template <typename T> T Any::CastTo() const
        {
            if (type == ClassType)
                return *reinterpret_cast<ClassStorage<T>*>(value)->Value;
            else
                throw std::bad_cast();
        }

        template <> inline bool Any::CastTo<bool>() const
        {
            switch (type)
            {
                case NullType:
                case MissingType:
                    return false;
                case BooleanType:
                    return GetBoolean();
                default:
                    return true;
            }
        }

        template <> inline char Any::CastTo<char>() const
        {
            return CastNumericValueTo<char>();
        }

        template <> inline unsigned char Any::CastTo<unsigned char>() const
        {
            return CastNumericValueTo<unsigned char>();
        }

        template <> inline short Any::CastTo<short>() const
        {
            return CastNumericValueTo<short>();
        }

        template <> inline unsigned short Any::CastTo<unsigned short>() const
        {
            return CastNumericValueTo<unsigned short>();
        }

        template <> inline int Any::CastTo<int>() const
        {
            return CastNumericValueTo<int>();
        }

        template <> inline unsigned int Any::CastTo<unsigned int>() const
        {
            return CastNumericValueTo<unsigned int>();
        }

        template <> inline long Any::CastTo<long>() const
        {
            return CastNumericValueTo<long>();
        }

        template <> inline unsigned long Any::CastTo<unsigned long>() const
        {
            return CastNumericValueTo<unsigned long>();
        }

        template <> inline int64 Any::CastTo<int64>() const
        {
            return CastNumericValueTo<int64>();
        }

        template <> inline uint64 Any::CastTo<uint64>() const
        {
            return CastNumericValueTo<uint64>();
        }

        template <> inline float Any::CastTo<float>() const
        {
            return CastNumericValueTo<float>();
        }

        template <> inline double Any::CastTo<double>() const
        {
            return CastNumericValueTo<double>();
        }

        template <> inline Color Any::CastTo<Color>() const
        {
            if (type == ColorType)
                return GetColor();
            else
                throw std::bad_cast();
        }

        template <> inline Matrix4 Any::CastTo<Matrix4>() const
        {
            if (type == Matrix4Type)
                return GetMatrix4();
            else
                throw std::bad_cast();
        }

        template <> inline Point Any::CastTo<Point>() const
        {
            if (type == PointType)
                return GetPoint();
            else
                throw std::bad_cast();
        }

        template <> inline Quaternion Any::CastTo<Quaternion>() const
        {
            if (type == QuaternionType)
                return GetQuaternion();
            else
                throw std::bad_cast();
        }

        template <> inline Rectangle Any::CastTo<Rectangle>() const
        {
            if (type == RectangleType)
                return GetRectangle();
            else
                throw std::bad_cast();
        }

        template <> inline String Any::CastTo<String>() const
        {
            if (type == StringType)
                return GetString();
            else
                throw std::bad_cast();
        }

        template <> inline UUID Any::CastTo<UUID>() const
        {
            if (type == UUIDType)
                return GetUUID();
            else
                throw std::bad_cast();
        }

        template <> inline Vector2 Any::CastTo<Vector2>() const
        {
            if (type == Vector2Type)
                return GetVector2();
            else
                throw std::bad_cast();
        }

        template <> inline Vector3 Any::CastTo<Vector3>() const
        {
            if (type == Vector3Type)
                return GetVector3();
            else
                throw std::bad_cast();
        }

        template <> inline Vector4 Any::CastTo<Vector4>() const
        {
            if (type == Vector4Type)
                return GetVector4();
            else
                throw std::bad_cast();
        }

        bool Any::operator < (const Any& right) const
        {
            return value < right.value;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename T> Any::SmallStorage<T>::SmallStorage(T value)
            : Value(value)
        {
        }

        template <typename T> Any::SmallStorage<T>::SmallStorage(const SmallStorage<T>& original)
            : Value(original.Value)
        {
        }

        template <typename T> Any::SmallStorage<T>::~SmallStorage()
        {
        }

        template <typename T> Any::Storage* Any::SmallStorage<T>::Clone() const
        {
            return new SmallStorage<T>(*this);
        }

        template <typename T> bool Any::SmallStorage<T>::Equals(const Storage* right) const 
        {
            return Value == static_cast<const SmallStorage<T>*>(right)->Value;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Any::ClassStorageBase::ClassStorageBase(const InstanceInfo& storedInstanceInfo)
            : StoredInstanceInfo(storedInstanceInfo)
        {
        }

        Any::ClassStorageBase::ClassStorageBase(const InstanceInfo& storedInstanceInfo, const String& tag)
            : StoredInstanceInfo(storedInstanceInfo),
              Tag(tag)
        {
        }

        Any::ClassStorageBase::ClassStorageBase(const ClassStorageBase& original)
            : StoredInstanceInfo(original.StoredInstanceInfo),
              Tag(original.Tag)
        {
        }

        Any::ClassStorageBase::~ClassStorageBase()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename T> Any::ClassStorage<T>::ClassStorage(const T& value)
            : ClassStorageBase(InstanceInfo::From<T>()),
              Value(new T(value))
        {
        }

        template <typename T> Any::ClassStorage<T>::ClassStorage(const T& value, const String& tag)
            : ClassStorageBase(InstanceInfo::From<T>(), tag),
              Value(new T(value))
        {
        }

        template <typename T> Any::ClassStorage<T>::ClassStorage(const ClassStorage<T>& original)
            : ClassStorageBase(original),
              Value(new T(*original.Value))
        {
        }

        template <typename T> Any::ClassStorage<T>::~ClassStorage()
        {
            delete Value;
        }

        template <typename T> Any::Storage* Any::ClassStorage<T>::Clone() const
        {
            return new ClassStorage<T>(*this);
        }

        template <typename T> bool Any::ClassStorage<T>::Equals(const Storage* right) const
        {
            const ClassStorage<T>* castedRight = static_cast<const ClassStorage<T>*>(right);
            return StoredInstanceInfo == castedRight->StoredInstanceInfo && Tag == castedRight->Tag &&
                   Any::Equals(*Value, *castedRight->Value);
        }

        template <typename T> bool Any::Equals(const T& a, const T& b)
        {
            return a == b;
        }

        template <typename T> bool Any::Equals(weak_ptr<T> a, weak_ptr<T> b)
        {
            return a.lock() == b.lock();
        }
    }

#endif
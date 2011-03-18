#pragma once
#ifndef __HALAK_ANY_H__
#define __HALAK_ANY_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/InstanceInfo.h>
#   include <Halak/Matrix4.h>
#   include <Halak/Point.h>
#   include <Halak/Quaternion.h>
#   include <Halak/Rectangle.h>
#   include <Halak/String.h>
#   include <Halak/UUID.h>
#   include <Halak/Vector2.h>
#   include <Halak/Vector3.h>
#   include <Halak/Vector4.h>

    namespace Halak
    {
        class Any
        {
            HKDeclareStructFOURCC('A', 'N', 'Y', '_');
            public:
                enum Type
                {
                    NullType,
                    MissingType,

                    BooleanType,
                    CharType,
                    UCharType,
                    ShortType,
                    UShortType,
                    IntType,
                    UIntType,
                    LongType,
                    ULongType,
                    Int64Type,
                    UInt64Type,
                    FloatType,
                    DoubleType,

                    ColorType,
                    Matrix4Type,
                    PointType,
                    QuaternionType,
                    RectangleType,
                    StringType,
                    UUIDType,
                    Vector2Type,
                    Vector3Type,
                    Vector4Type,

                    ClassType,
                };
            
            public:
                inline Any();
                inline Any(bool value);
                inline Any(char value);
                inline Any(unsigned char value);
                inline Any(short value);
                inline Any(unsigned short value);
                inline Any(int value);
                inline Any(unsigned int value);
                inline Any(long value);
                inline Any(unsigned long value);
                inline Any(int64 value);
                inline Any(uint64 value);
                inline Any(float value);
                inline Any(double value);
                inline Any(Color value);
                inline Any(const Matrix4& value);
                inline Any(Point value);
                inline Any(Quaternion value);
                inline Any(Rectangle value);
                inline Any(const char* value);
                inline Any(const String& value);
                inline Any(UUID value);
                inline Any(Vector2 value);
                inline Any(Vector3 value);
                inline Any(Vector4 value);
                template <typename T> Any(const T& value);
                template <typename T> Any(const T& value, const String& tag);
                inline Any(const Any& original);
                ~Any();

                inline Type GetType() const;
                inline bool GetBoolean() const;
                inline char GetChar() const;
                inline unsigned char GetUChar() const;
                inline short GetShort() const;
                inline unsigned short GetUShort() const;
                inline int GetInt() const;
                inline unsigned int GetUInt() const;
                inline long GetLong() const;
                inline unsigned long GetULong() const;
                inline int64 GetInt64() const;
                inline uint64 GetUInt64() const;
                inline float GetFloat() const;
                inline double GetDouble() const;
                inline Color GetColor() const;
                inline const Matrix4& GetMatrix4() const;
                inline Point GetPoint() const;
                inline Quaternion GetQuaternion() const;
                inline Rectangle GetRectangle() const;
                inline const String& GetString() const;
                inline UUID GetUUID() const;
                inline Vector2 GetVector2() const;
                inline Vector3 GetVector3() const;
                inline Vector4 GetVector4() const;
                template <typename T> T CastTo() const;

                // !ONLY! Class
                const String& GetTag() const;
                const InstanceInfo& GetStoredInstanceInfo() const;

                Any& operator = (const Any& right);

                bool operator == (const Any& right) const;
                bool operator != (const Any& right) const;

                // std::map에 Key로 쓰이기 위하여 만들어졌습니다.
                inline bool operator < (const Any& right) const;

            public:
                static const Any Null;
                static const Any Missing;

            private:
                struct MissingTag { };
                Any(MissingTag);

                template <typename T> T CastNumericValueTo() const;

            private:
                Type  type;
                void* value;

            private:
                struct Storage
                {
                    virtual ~Storage() { }

                    virtual Storage* Clone() const = 0;
                    virtual bool Equals(const Storage* right) const = 0;
                };

                template <typename T> struct SmallStorage : Storage
                {
                    T Value;

                    SmallStorage(T value);
                    SmallStorage(const SmallStorage<T>& original);
                    virtual ~SmallStorage();

                    virtual Storage* Clone() const;
                    virtual bool Equals(const Storage* right) const;
                };

                struct ClassStorageBase : Storage
                {
                    InstanceInfo StoredInstanceInfo;
                    String Tag;

                    inline ClassStorageBase(const InstanceInfo& storedInstanceInfo);
                    inline ClassStorageBase(const InstanceInfo& storedInstanceInfo, const String& tag);
                    inline ClassStorageBase(const ClassStorageBase& original);
                    inline virtual ~ClassStorageBase();
                };

                template <typename T> struct ClassStorage : ClassStorageBase
                {
                    T* Value;
                    const TypeInfo* Type;

                    ClassStorage(const T& value);
                    ClassStorage(const T& value, const String& tag);
                    ClassStorage(const ClassStorage<T>& original);
                    virtual ~ClassStorage();

                    virtual Storage* Clone() const;
                    virtual bool Equals(const Storage* right) const;
                };
        };
    }

#   include <Halak/Any.inl>

#endif
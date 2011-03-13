#pragma once
#ifndef __HALAK_ANYPTR_H__
#define __HALAK_ANYPTR_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class AnyPtr
        {
            HKDeclareStructFOURCC('A', 'N', 'Y', 'P');

            public:
                enum Type
                {
                    NullType,
                    RawPointerType,
                    SharedPointerType,
                    WeakPointerType,
                };

            public:
                inline AnyPtr();
                template <typename T> AnyPtr(T* pointer);
                template <typename T> AnyPtr(shared_ptr<T> pointer);
                template <typename T> AnyPtr(weak_ptr<T> pointer);
                inline AnyPtr(const AnyPtr& original);
                inline ~AnyPtr();

                inline const TypeInfo* GetPointeeType() const;

                template <typename T> T* GetRawPointer() const;
                template <typename T> shared_ptr<T> GetSharedPointer() const;
                template <typename T> weak_ptr<T> GetWeakPointer() const;

                template <typename T> T* CastTo() const;
                void* DynamicCastTo(const ClassInfo* toClass) const;

                AnyPtr& operator = (const AnyPtr& right);

                bool operator == (const AnyPtr& right) const;
                bool operator != (const AnyPtr& right) const;

                // std::map에 Key로 쓰이기 위하여 만들어졌습니다.
                inline bool operator < (const AnyPtr& right) const;

            public:
                static const AnyPtr Null;

            private:
                struct Storage;

                Type type;
                Storage* storage;

            private:
                struct Storage
                {
                    const TypeInfo* PointeeType;

                    inline Storage(const TypeInfo* pointeeType);
                    inline Storage(const Storage& original);
                    inline virtual ~Storage();

                    virtual Storage* Clone() const = 0;
                    virtual void* DynamicCastTo(const ClassInfo* toClass) const = 0;
                    virtual void* ToVoidPointer() const = 0;
                };

                template <typename T> struct RawPointerStorage : Storage
                {
                    T* Value;

                    RawPointerStorage(T* value);
                    RawPointerStorage(const RawPointerStorage<T>& original);

                    virtual Storage* Clone() const;
                    virtual void* DynamicCastTo(const ClassInfo* toClass) const;
                    virtual void* ToVoidPointer() const;
                };

                template <typename T> struct SharedPointerStorage : Storage
                {
                    shared_ptr<T> Value;

                    SharedPointerStorage(shared_ptr<T> value);
                    SharedPointerStorage(const SharedPointerStorage<T>& original);

                    virtual Storage* Clone() const;
                    virtual void* DynamicCastTo(const ClassInfo* toClass) const;
                    virtual void* ToVoidPointer() const;
                };

                template <typename T> struct WeakPointerStorage : Storage
                {
                    weak_ptr<T> Value;

                    WeakPointerStorage(weak_ptr<T> value);
                    WeakPointerStorage(const WeakPointerStorage<T>& original);

                    virtual Storage* Clone() const;
                    virtual void* DynamicCastTo(const ClassInfo* toClass) const;
                    virtual void* ToVoidPointer() const;
                };
        };
    }

#   include <Halak/AnyPtr.inl>

#endif
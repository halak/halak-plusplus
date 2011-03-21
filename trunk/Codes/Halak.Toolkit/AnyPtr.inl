#include <Halak/DynamicCast.h>
#include <Halak/TypeLibrary.h>

namespace Halak
{
    AnyPtr::AnyPtr()
        : storage(nullptr),
          type(NullType)
    {
    }

    template <typename T> AnyPtr::AnyPtr(T* pointer)
        : type(pointer ? RawPointerType : NullType),
          storage(pointer ? new RawPointerStorage<T>(pointer) : nullptr)
    {
    }

    template <typename T> AnyPtr::AnyPtr(SharedPointer<T> pointer)
        : type(pointer ? SharedPointerType : NullType),
          storage(pointer ? new SharedPointerStorage<T>(pointer) : nullptr)              
    {
    }

    template <typename T> AnyPtr::AnyPtr(WeakPointer<T> pointer)
        : type(pointer.IsAlive() ? WeakPointerType : NullType),
          storage(pointer.IsAlive() ? new WeakPointerStorage<T>(pointer) : nullptr)
    {
    }

    AnyPtr::AnyPtr(const AnyPtr& original)
        : type(original.type),
          storage(original.storage ? original.storage->Clone() : nullptr)
    {
    }

    AnyPtr::~AnyPtr()
    {
        delete storage;
    }

    const TypeInfo* AnyPtr::GetPointeeType() const
    {
        return storage ? storage->PointeeType : nullptr;
    }

    template <typename T> T* AnyPtr::GetRawPointer() const
    {
        return nullptr;
    }

    template <typename T> SharedPointer<T> AnyPtr::GetSharedPointer() const
    {
        return nullptr;
    }

    template <typename T> WeakPointer<T> AnyPtr::GetWeakPointer() const
    {
        return nullptr;
    }

    template <typename T> T* AnyPtr::CastTo() const
    {
        return nullptr;
    }

    bool AnyPtr::operator < (const AnyPtr& right) const
    {
        return storage < right.storage;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    AnyPtr::Storage::Storage(const TypeInfo* pointeeType)
        : PointeeType(pointeeType)
    {
    }

    AnyPtr::Storage::Storage(const Storage& original)
        : PointeeType(original.PointeeType)
    {
    }

    AnyPtr::Storage::~Storage()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T> AnyPtr::RawPointerStorage<T>::RawPointerStorage(T* value)
        : Storage(TypeLibrary::GetInstance().GetTypeInfo<T>()),
          Value(value)
    {
    }

    template <typename T> AnyPtr::RawPointerStorage<T>::RawPointerStorage(const RawPointerStorage<T>& original)
        : Storage(original),
          Value(original.Value)
    {
    }

    template <typename T> AnyPtr::Storage* AnyPtr::RawPointerStorage<T>::Clone() const
    {
        return new RawPointerStorage<T>(*this);
    }

    template <typename T> void* AnyPtr::RawPointerStorage<T>::DynamicCastTo(const ClassInfo* toClass) const
    {
        return DynamicCast(toClass, Value);
    }

    template <typename T> void* AnyPtr::RawPointerStorage<T>::ToVoidPointer() const
    {
        return Value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T> AnyPtr::SharedPointerStorage<T>::SharedPointerStorage(SharedPointer<T> value)
        : Storage(TypeLibrary::GetInstance().GetTypeInfo<T>()),
          Value(value)
    {
    }

    template <typename T> AnyPtr::SharedPointerStorage<T>::SharedPointerStorage(const SharedPointerStorage<T>& original)
        : Storage(original),
          Value(original.Value)
    {
    }

    template <typename T> AnyPtr::Storage* AnyPtr::SharedPointerStorage<T>::Clone() const
    {
        return new SharedPointerStorage<T>(*this);
    }

    template <typename T> void* AnyPtr::SharedPointerStorage<T>::DynamicCastTo(const ClassInfo* toClass) const
    {
        return DynamicCast(toClass, Value);
    }

    template <typename T> void* AnyPtr::SharedPointerStorage<T>::ToVoidPointer() const
    {
        return Value.GetPointee();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T> AnyPtr::WeakPointerStorage<T>::WeakPointerStorage(WeakPointer<T> value)
        : Storage(TypeLibrary::GetInstance().GetTypeInfo<T>()),
          Value(value)
    {
    }

    template <typename T> AnyPtr::WeakPointerStorage<T>::WeakPointerStorage(const WeakPointerStorage<T>& original)
        : Storage(original),
          Value(original.Value)
    {
    }

    template <typename T> AnyPtr::Storage* AnyPtr::WeakPointerStorage<T>::Clone() const
    {
        return new WeakPointerStorage<T>(*this);
    }

    template <typename T> void* AnyPtr::WeakPointerStorage<T>::DynamicCastTo(const ClassInfo* toClass) const
    {
        return DynamicCast(toClass, Value);
    }

    template <typename T> void* AnyPtr::WeakPointerStorage<T>::ToVoidPointer() const
    {
        if (Value.IsAlive())
            return Value.Lock().GetPointee();
        else
            return nullptr;
    }
}
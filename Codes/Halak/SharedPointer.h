#pragma once
#ifndef __HALAK_SHAREDPOINTER_H__
#define __HALAK_SHAREDPOINTER_H__

#   include <Halak/Foundation.h>
#   include <Halak/SharedObject.h>
#   include <Halak/Internal/ReferenceCount.h>

    namespace Halak
    {
        template <typename T> class SharedPointer
        {
            public:
                typedef T PointeeType;

            public:
                inline SharedPointer();
                inline SharedPointer(T* pointee);
                inline SharedPointer(const SharedPointer<T>& original);
                inline ~SharedPointer();

                inline void Reset();
                inline void Reset(const SharedPointer<T>& right);
                inline void Reset(T* right);

                inline void Swap(SharedPointer<T>& right);

                inline T* GetPointee() const;
                inline int GetReferenceCount() const;
                inline int GetWeakReferenceCount() const;

                inline SharedPointer<T>& operator = (const SharedPointer<T>& right);

                inline bool operator == (const SharedPointer<T>& right) const;
                inline bool operator == (T* right) const;
                inline bool operator != (const SharedPointer<T>& right) const;
                inline bool operator != (T* right) const;

                inline operator T* () const;
                inline T& operator * () const;
                inline T* operator -> () const;

                template <typename U> operator SharedPointer<U>() const
                {
                    return SharedPointer<U>(static_cast<U*>(pointee), referenceCount);
                }

            private:
                inline SharedPointer(T* pointee, ReferenceCount* referenceCount);

                inline ReferenceCount* AcquireReferenceCount(SharedObject* instance);
                inline ReferenceCount* AcquireReferenceCount(void* instance);

            private:
                T* pointee;
                ReferenceCount* referenceCount;

                template <typename U> friend class SharedPointer;
                template <typename T> friend class WeakPointer;
                template <typename To, typename From> friend SharedPointer<To> StaticCast(const SharedPointer<From>& from);
                template <typename To, typename From> friend SharedPointer<To> DynamicCast(const SharedPointer<From>& from);
                friend class SharedObject;
        };
    }

#   include <Halak/SharedPointer.inl>

#endif
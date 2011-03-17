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
                inline SharedPointer();
                inline SharedPointer(T* pointee);
                inline SharedPointer(const SharedPointer<T>& original);
                inline ~SharedPointer();

                inline void Reset(const SharedPointer<T>& right);
                inline void Reset(T* right);

                inline T* GetPointee() const;
                inline int GetReferenceCount() const;
                inline int GetWeakReferenceCount() const;

                inline SharedPointer<T>& operator = (const SharedPointer<T>& right);
                inline SharedPointer<T>& operator = (T* right);

                inline bool operator == (const SharedPointer<T>& right) const;
                inline bool operator == (T* right) const;
                inline bool operator != (const SharedPointer<T>& right) const;
                inline bool operator != (T* right) const;

                inline operator T* () const;
                inline T& operator * () const;
                inline T* operator -> () const;

            private:
                template <typename U>
                inline ReferenceCount* AcquireReferenceCount(U* instance) { return instance ? new ReferenceCount() : 0; }
                inline ReferenceCount* AcquireReferenceCount(SharedObject* instance);

            private:
                T* pointee;
                ReferenceCount* referenceCount;
        };
    }

#   include <Halak/SharedPointer.inl>

#endif
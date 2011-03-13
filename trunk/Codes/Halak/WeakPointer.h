#pragma once
#ifndef __HALAK_WEAKPOINTER_H__
#define __HALAK_WEAKPOINTER_H__

#   include <Halak/SharedPointer.h>

    namespace Halak
    {
        template <typename T> class WeakPointer;
        template <typename T> class SharedPointer;

        template <typename T> class WeakPointer
        {
            public:
                inline WeakPointer();
                inline WeakPointer(const SharedPointer<T>& pointer);
                inline WeakPointer(const WeakPointer<T>& original);
                inline ~WeakPointer();

                inline SharedPointer<T> Lock() const;

                inline bool IsAlive() const;

                inline WeakPointer<T>& operator = (const WeakPointer<T>& right) const;
                inline WeakPointer<T>& operator = (const SharedPointer<T>& right) const;

                inline bool operator == (const WeakPointer<T>& right) const;
                inline bool operator == (const SharedPointer<T>& right) const;
                inline bool operator == (T* right) const;
                inline bool operator != (const WeakPointer<T>& right) const;
                inline bool operator != (const SharedPointer<T>& right) const;
                inline bool operator != (T* right) const;

                inline operator T* () const;
                inline operator SharedPointer<T> () const;

            private:
                T* pointee;
                ReferenceCount* referenceCount;
        };
    }

#   include <Halak/WeakPointer.inl>

#endif
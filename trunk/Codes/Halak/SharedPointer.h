#pragma once
#ifndef __HALAK_SHAREDPOINTER_H__
#define __HALAK_SHAREDPOINTER_H__

    namespace Halak
    {
        template <typename T> class SharedPointer
        {
            public:
                inline SharedPointer();
                inline SharedPointer(T* pointee);
                inline SharedPointer(const SharedPointer<T>& original);
                inline ~SharedPointer();

                inline T* GetPointee() const;

                inline SharedPointer<T>& operator = (const SharedPointer<T>& right) const;
                inline SharedPointer<T>& operator = (T* right) const;

                inline bool operator == (const SharedPointer<T>& right) const;
                inline bool operator == (T* right) const;
                inline bool operator != (const SharedPointer<T>& right) const;
                inline bool operator != (T* right) const;

                inline operator T* () const;
                inline T& operator * () const;
                inline T* operator -> () const;

            private:
                T* pointee;
        };
    }

#   include <Halak/SharedPointer.inl>

#endif
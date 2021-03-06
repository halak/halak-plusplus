#pragma once
#ifndef __HALAK_NULLPOINTER_H__
#define __HALAK_NULLPOINTER_H__

#   include <Halak/Foundation.h>
#   include <Halak/SharedPointer.h>
#   include <Halak/WeakPointer.h>

    namespace Halak
    {
        static struct NullPointer
        {
            template <typename T> bool operator == (      T* right)                { return right ? false : true; }
            template <typename T> bool operator == (const T* right)                { return right ? false : true; }
            template <typename T> bool operator == (const SharedPointer<T>& right) { return right.GetPointee() ? false : true; }
            template <typename T> bool operator == (const WeakPointer<T>& right)   { return right.IsAlive() == false; }

            template <typename T> bool operator != (      T* right)                { return right ? true : false; }
            template <typename T> bool operator != (const T* right)                { return right ? true : false; }
            template <typename T> bool operator != (const SharedPointer<T>& right) { return right.GetPointee() ? true : false; }
            template <typename T> bool operator != (const WeakPointer<T>& right)   { return right.IsAlive(); }

            template <typename T> friend bool operator == (      T* left, NullPointer)                { return left ? false : true; }
            template <typename T> friend bool operator == (const T* left, NullPointer)                { return left ? false : true; }
            template <typename T> friend bool operator == (const SharedPointer<T>& left, NullPointer) { return left.GetPointee() ? false : true; }
            template <typename T> friend bool operator == (const WeakPointer<T>& left, NullPointer)   { return left.IsAlive() == false; }

            template <typename T> friend bool operator != (      T* left, NullPointer)                { return left ? true : false; }
            template <typename T> friend bool operator != (const T* left, NullPointer)                { return left ? true : false; }
            template <typename T> friend bool operator != (const SharedPointer<T>& left, NullPointer) { return left.GetPointee() ? true : false; }
            template <typename T> friend bool operator != (const WeakPointer<T>& left, NullPointer)   { return left.IsAlive(); }

            template <typename T> operator T* () const               { return 0; }
            template <typename T> operator SharedPointer<T> () const { return SharedPointer<T>(); }
            template <typename T> operator WeakPointer<T> () const   { return WeakPointer<T>(); }
        }nullptr;
    }

#endif
#pragma once
#ifndef __HALAK_DISPOSABLE_INTERFACE_INL__
#define __HALAK_DISPOSABLE_INTERFACE_INL__

    namespace Halak
    {
        template <typename T> bool DynamicDispose(T* instance)
        {
            if (IDisposable* disposable = dynamic_cast<IDisposable*>(instance))
            {
                disposable->Dispose();
                return true;
            }
            else
                return false;
        }

        template <typename T> bool DynamicDispose(shared_ptr<T> instance)
        {
            return DynamicDispose<T>(instance.get());
        }
    }

#endif
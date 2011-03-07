#pragma once
#ifndef __HALAK_DYNAMICCAST_H__
#define __HALAK_DYNAMICCAST_H__

#    include <Halak/FWD.h>
#   include <Halak/Assert.h>
#   include <Halak/ClassInfo.h>
#   include <Halak/TypeLibrary.h>

    namespace Halak
    {
        template <typename T> inline void* DynamicCast(const ClassInfo* toClass, T* from)
        {
            HKAssertDebug(toClass && toClass->IsClass());

            const ClassInfo* fromClass = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<T>());
            HKAssertDebug(fromClass && fromClass->IsClass());

            const ClassInfo* actualClass = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType(from));
            HKAssertDebug(actualClass && actualClass->IsClass());

            const int fromOffset = actualClass->GetOffset(fromClass);
            if (fromOffset < 0)
                return nullptr;

            const int toOffset = actualClass->GetOffset(toClass);
            if (toOffset < 0)
                return nullptr;

            return reinterpret_cast<void*>(reinterpret_cast<byte*>(from) - fromOffset + toOffset);
        }

        template <typename T> inline const void* DynamicCast(const ClassInfo* toClass, const T* from)
        {
            return const_cast<const void*>(DynamicCast<T>(toClass, const_cast<T*>(from)));
        }

        template <typename T> inline void* DynamicCast(const ClassInfo* toClass, shared_ptr<T> from)
        {
            return DynamicCast<T>(toClass, static_cast<T*>(from.get()));
        }

        template <typename T> inline void* DynamicCast(const ClassInfo* toClass, weak_ptr<T> from)
        {
            if (from.expired())
                return nullptr;
            else
                return DynamicCast<T>(toClass, static_cast<T*>(from.lock().get()));
        }
    }

#endif
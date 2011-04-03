#pragma once
#ifndef __HALAK_TOOLKIT_DYNAMICCAST_H__
#define __HALAK_TOOLKIT_DYNAMICCAST_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/ClassInfo.h>
#   include <Halak.Toolkit/TypeLibrary.h>
#   include <Halak/Assert.h>

    namespace Halak
    {
        namespace Toolkit
        {
            template <typename T> inline void* DynamicCast(const ClassInfo* toClass, T* from)
            {
                HKAssertDebug(toClass && toClass->IsClass());

                const ClassInfo* fromClass = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().Find<T>());
                HKAssertDebug(fromClass && fromClass->IsClass());

                const ClassInfo* actualClass = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().Find(from));
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

            template <typename T> inline void* DynamicCast(const ClassInfo* toClass, SharedPointer<T> from)
            {
                return DynamicCast<T>(toClass, static_cast<T*>(from.GetPointee()));
            }

            template <typename T> inline void* DynamicCast(const ClassInfo* toClass, WeakPointer<T> from)
            {
                if (from.IsAlive())
                    return DynamicCast<T>(toClass, static_cast<T*>(from.Lock().GetPointee()));
                else
                    return nullptr;
            }
        }
    }

#endif
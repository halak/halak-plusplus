#pragma once
#ifndef __HALAK_POINTERCASTS_H__
#define __HALAK_POINTERCASTS_H__

#   include <Halak/Foundation.h>
#   include <Halak/NullPointer.h>
#   include <Halak/SharedObject.h>
#   include <Halak/WeakPointer.h>

    namespace Halak
    {
        template <typename To, typename From> inline To* StaticCast(From* from)
        {
            return static_cast<To*>(from);
        }

        template <typename To, typename From> inline SharedPointer<To> StaticCast(const SharedPointer<From>& from)
        {
            return SharedPointer<To>(static_cast<To*>(from.pointee), from.referenceCount);
        }

        template <typename To, typename From> inline WeakPointer<To> StaticCast(const WeakPointer<From>& from)
        {
            return WeakPointer<To>(static_cast<To*>(from.pointee), from.referenceCount);
        }

        template <typename To, typename From> inline To* DynamicCast(From* from)
        {
            return static_cast<To*>(from);
        }

        template <typename To, typename From> inline SharedPointer<To> DynamicCast(const SharedPointer<From>& from)
        {
            return SharedPointer<To>(dynamic_cast<To*>(from.pointee), from.referenceCount);
        }

        template <typename To, typename From> inline WeakPointer<To> DynamicCast(const WeakPointer<From>& from)
        {
            return WeakPointer<To>(dynamic_cast<To*>(from.pointee), from.referenceCount);
        }
    }

#endif
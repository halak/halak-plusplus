#pragma once
#ifndef __HAlAK_SHAREDOBJECT_H__
#define __HAlAK_SHAREDOBJECT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class SharedObject;
        class ReferenceCount;
        template <typename T> class SharedPointer;
        template <typename T> class WeakPointer;

        class SharedObject
        {
            public:
                virtual ~SharedObject();

                template <typename T> SharedPointer<T> CastTo();

#               if (defined(HALAK_RTTI))
                    template <typename T> SharedPointer<T> DynamicCastTo();
#               endif

            protected:
                SharedObject();

            private:
                ReferenceCount* referenceCount;

                template <typename T> friend class SharedPointer;
                template <typename T> friend class WeakPointer;
        };
    }

#   include <Halak/SharedObject.inl>

#endif
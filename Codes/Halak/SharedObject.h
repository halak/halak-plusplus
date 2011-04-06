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

            protected:
                SharedObject();

                template <typename To> SharedPointer<To> This();
                template <typename To, typename ThisType> SharedPointer<To> This(ThisType* thisInstance);

            private:
                ReferenceCount* referenceCount;

                template <typename T> friend class SharedPointer;
                template <typename T> friend class WeakPointer;
        };
    }

#   include <Halak/SharedObject.inl>

#endif
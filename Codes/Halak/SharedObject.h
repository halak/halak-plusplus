#pragma once
#ifndef __HAlAK_SHAREDOBJECT_H__
#define __HAlAK_SHAREDOBJECT_H__

    namespace Halak
    {
        class ReferenceCount;

        class SharedObject
        {
            public:
                SharedObject();
                virtual ~SharedObject();

            private:
                ReferenceCount* referenceCount;
                friend template <typename T> class SharedPointer;
                friend template <typename T> class WeakPointer;
        };
    }

#   include <Halak/SharedObject.inl>

#endif
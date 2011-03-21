#pragma once
#ifndef __HAlAK_SHAREDOBJECT_H__
#define __HAlAK_SHAREDOBJECT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class SharedObject;
        class ReferenceCount;

        class SharedObject
        {
            public:
                virtual ~SharedObject();

            protected:
                SharedObject();

            private:
                ReferenceCount* referenceCount;
                template <typename T> friend class SharedPointer;
                template <typename T> friend class WeakPointer;
        };
    }

#endif
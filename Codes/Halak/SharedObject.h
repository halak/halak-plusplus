#pragma once
#ifndef __HAlAK_SHAREDOBJECT_H__
#define __HAlAK_SHAREDOBJECT_H__

#   include <Halak/Foundation.h>
#   include <Halak/Object.h>

    namespace Halak
    {
        class SharedObject;
        class ReferenceCount;

        class SharedObject : public Object
        {
            HKDeclareObjectFOURCC('S', 'H', 'O', 'B');
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
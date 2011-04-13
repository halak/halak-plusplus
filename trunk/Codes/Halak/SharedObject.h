#pragma once
#ifndef __HAlAK_SHAREDOBJECT_H__
#define __HAlAK_SHAREDOBJECT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class SharedObject;
        class SharedObjectLife;
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
                SharedObjectLife* life;

                template <typename T> friend class SharedPointer;
                template <typename T> friend class WeakPointer;

            private:
                SharedObject(const SharedObject&);
                SharedObject& operator = (const SharedObject&);
        };
    }

#   include <Halak/SharedObject.inl>

#endif
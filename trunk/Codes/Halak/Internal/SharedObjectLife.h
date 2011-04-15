#pragma once
#ifndef __HALAK_SHAREDOBJECTLIFE_H__
#define __HALAK_SHAREDOBJECTLIFE_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class SharedObjectLife;
        class SharedObject;

        class SharedObjectLife
        {
            HKThisIsNoncopyableClass(SharedObjectLife);
            public:
#               if (defined(HALAK_PLATFORM_WINDOWS))
                    typedef long IntType;
#               else
                    typedef int IntType;
#               endif

            public:
                inline SharedObjectLife(SharedObject* pointee);

                void IncreaseStrongCount();
                bool DecreaseStrongCount();
                void IncreaseWeakCount();
                void DecreaseWeakCount();

                inline int GetStrong() const;
                inline int GetWeak() const;

                inline bool IsAlive() const;

            private:
                SharedObject* pointee;
                IntType strong;
                IntType weak;
        };
    }

#   include <Halak/Internal/SharedObjectLife.inl>

#endif
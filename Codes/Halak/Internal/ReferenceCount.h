#pragma once
#ifndef __HALAK_REFERENCECOUNT_H__
#define __HALAK_REFERENCECOUNT_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class ReferenceCount
        {
            public:
#               if defined(HALAK_PLATFORM_WINDOWS)
                    typedef long IntType;
#               else
                    typedef int IntType;
#               endif

            public:
                inline ReferenceCount();
                inline ReferenceCount(const ReferenceCount& original);

                void IncreaseStrongCount();
                bool DecreaseStrongCount();
                void IncreaseWeakCount();
                void DecreaseWeakCount();

                inline int GetStrong() const;
                inline int GetWeak() const;

                inline bool IsAlive() const;

                inline ReferenceCount& operator = (const ReferenceCount&);

            private:
                IntType strong;
                IntType weak;
        };
    }

#   include <Halak/Internal/ReferenceCount.inl>

#endif
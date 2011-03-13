#pragma once
#ifndef __HALAK_REFERENCECOUNT_H__
#define __HALAK_REFERENCECOUNT_H__

#   include <Halak/BuildConfiguration.h>

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

                void IncreaseStrongCount();
                bool DecreaseStrongCount();
                void IncreaseWeakCount();
                void DecreaseWeakCount();

                inline bool IsAlive() const;

            private:
                IntType strong;
                IntType weak;

            private:
                ReferenceCount(const ReferenceCount&);
                ReferenceCount& operator = (const ReferenceCount&);
        };
    }

#   include <Halak/Internal/ReferenceCount.inl>

#endif
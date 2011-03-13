#include <Halak/Internal/ReferenceCount.h>
#include <Halak/BuildConfiguration.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   include <windows.h>

    namespace Halak
    {
        void ReferenceCount::IncreaseStrongCount()
        {
            InterlockedIncrement(&strong);
        }

        bool ReferenceCount::DecreaseStrongCount()
        {
            InterlockedDecrement(&strong);
            return strong == 0;
        }

        void ReferenceCount::IncreaseWeakCount()
        {
            InterlockedIncrement(&weak);
        }

        void ReferenceCount::DecreaseWeakCount()
        {
            InterlockedDecrement(&weak);
            if (strong == 0 && weak == 0)
                delete this;
        }
    }

#endif
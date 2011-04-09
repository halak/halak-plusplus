#include <Halak/PCH.h>
#include <Halak/Internal/ReferenceCount.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   define WIN32_LEAN_AND_MEAN
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
            if (strong == 0)
            {
                if (weak == 0)
                    delete this;
                return true;
            }
            else
                return false;
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
#include <Halak/PCH.h>
#include <Halak/Internal/SharedObjectLife.h>
#include <Halak/SharedObject.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>

    namespace Halak
    {
        void SharedObjectLife::IncreaseStrongCount()
        {
            InterlockedIncrement(&strong);
        }

        bool SharedObjectLife::DecreaseStrongCount()
        {
            InterlockedDecrement(&strong);
            if (strong == 0)
            {
                delete pointee;

                if (weak == 0)
                    delete this;

                return true;
            }
            else
                return false;
        }

        void SharedObjectLife::IncreaseWeakCount()
        {
            InterlockedIncrement(&weak);
        }

        void SharedObjectLife::DecreaseWeakCount()
        {
            InterlockedDecrement(&weak);
            if (strong == 0 && weak == 0)
                delete this;
        }
    }

#endif
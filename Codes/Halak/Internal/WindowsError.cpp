#include <Halak/PCH.h>
#include <Halak/Internal/WindowsError.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>

    namespace Halak
    {
        String GetWindowsErrorMessage(DWORD errorCode)
        {
            LPVOID messageBuffer = NULL;

            FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                          NULL, 
                          errorCode, 
                          MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                          reinterpret_cast<LPSTR>(&messageBuffer),
                          0, NULL);

            String result = reinterpret_cast<LPSTR>(&messageBuffer);

            LocalFree(messageBuffer);

            return result;
        }
    }

#endif
#pragma once
#ifndef __HALAK_WINDOWSERROR_H__
#define __HALAK_WINDOWSERROR_H__

#   include <Halak/Foundation.h>

#   if (defined(HALAK_PLATFORM_WINDOWS))

#       include <Halak/String.h>

        namespace Halak
        {
            String GetWindowsErrorMessage(dword errorCode);
        }

#   endif

#endif
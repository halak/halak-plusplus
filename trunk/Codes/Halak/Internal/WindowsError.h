#pragma once
#ifndef __HALAK_WINDOWSERROR_H__
#define __HALAK_WINDOWSERROR_H__

#   if (defined(WIN32) || defined(WIN64))

#       include <Halak/String.h>

#       define WIN32_LEAN_AND_MEAN
#       include <windows.h>

        namespace Halak
        {
            String GetWindowsErrorMessage(DWORD errorCode);
        }

#   endif

#endif
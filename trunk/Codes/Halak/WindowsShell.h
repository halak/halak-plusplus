#pragma once
#ifndef __HALAK_WINDOWSSHELL_H__
#define __HALAK_WINDOWSSHELL_H__

#   include <Halak/FWD.h>
#   include <Halak/BuildConfiguration.h>

#   if (defined(HALAK_PLATFORM_WINDOWS))
        namespace Halak
        {
            class WindowsShell
            {
                HKThisIsStaticClass(WindowsShell);
                public:
            };
        }
#   endif

#endif
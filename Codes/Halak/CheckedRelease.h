#pragma once
#ifndef __HALAK_CHECKEDRELEASE_H__
#define __HALAK_CHECKEDRELEASE_H__

#   include <Halak/Foundation.h>

#   if (defined(HALAK_PLATFORM_WINDOWS))

        namespace Halak
        {
            template <typename T> void CheckedRelease(T*& comObject)
            {
                if (comObject)
                {
                    comObject->Release();
                    comObject = 0;
                }
            }
        }

#   endif

#endif
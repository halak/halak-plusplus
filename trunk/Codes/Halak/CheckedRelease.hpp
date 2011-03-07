#pragma once
#ifndef __HALAK_CHECKEDRELEASE_HPP__
#define __HALAK_CHECKEDRELEASE_HPP__

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

#endif
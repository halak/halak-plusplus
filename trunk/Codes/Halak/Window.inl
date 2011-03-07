#pragma once
#ifndef __HALAK_WINDOW_INL__
#define __HALAK_WINDOW_INL__

namespace Halak
{
    Signal<int>& Window::MouseWheel()
    {
        return mouseWheel;
    }
}

#endif
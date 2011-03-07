#pragma once
#ifndef __HALAK_WXTOOLKIT_WINDOWEVENTS_INTERFACE__
#define __HALAK_WXTOOLKIT_WINDOWEVENTS_INTERFACE__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Signal.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class IWindowSignals
            {
                public:
                    virtual ~IWindowSignals() { }

                    virtual Signal<bool>& VisibleChanged() = 0;
            };
        }
    }

#endif
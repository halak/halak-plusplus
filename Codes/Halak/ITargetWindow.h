#pragma once
#ifndef __HALAK_TARGETWINDOW_INTERFACE__
#define __HALAK_TARGETWINDOW_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ITargetWindow
        {
            HKInterfaceFOURCC('I', 'T', 'G', 'W');
            public:
                virtual ~ITargetWindow() { }

                virtual UIWindow* GetTarget() const = 0;
        };
    }

#endif
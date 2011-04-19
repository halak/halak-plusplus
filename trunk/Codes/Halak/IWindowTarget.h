#pragma once
#ifndef __HALAK_WINDOWTARGET_INTERFACE__
#define __HALAK_WINDOWTARGET_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IWindowTarget
        {
            HKInterfaceFOURCC('I', 'T', 'G', 'W');
            public:
                virtual ~IWindowTarget() { }

                virtual UIWindow* GetTarget() const = 0;
                virtual void SetTarget(UIWindow* value) = 0;
        };
    }

#endif
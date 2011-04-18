#pragma once
#ifndef __HALAK_UIFIXEDTARGETWINDOW_H__
#define __HALAK_UIFIXEDTARGETWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/ITargetWindow.h>

    namespace Halak
    {
        class UIFixedTargetWindow : public GameComponent, public ITargetWindow
        {
            HKClassFOURCC('U', 'I', 'F', 'T');
            public:
                UIFixedTargetWindow();
                UIFixedTargetWindow(UIWindow* target);
                virtual ~UIFixedTargetWindow();

                virtual UIWindow* GetTarget() const;
                virtual void SetTarget(UIWindow* value);

                virtual void* QueryInterface(uint classID);

            private:
                UIWindow* target;
        };
    }

#endif
#pragma once
#ifndef __HALAK_UIFIXEDTARGETWINDOW_H__
#define __HALAK_UIFIXEDTARGETWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IWindowTarget.h>

    namespace Halak
    {
        class UISimpleWindowTarget : public GameComponent, public IWindowTarget
        {
            HKClassFOURCC('U', 'I', 'S', 'T');
            public:
                UISimpleWindowTarget();
                UISimpleWindowTarget(UIWindow* target);
                virtual ~UISimpleWindowTarget();

                virtual UIWindow* GetTarget() const;
                virtual void SetTarget(UIWindow* value);

                virtual void* QueryClass(uint32 classID);

            private:
                UIWindow* target;
        };
    }

#endif
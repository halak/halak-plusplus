#pragma once
#ifndef __HALAK_UIKEYBOARDEVENTDISPATCHER_H__
#define __HALAK_UIKEYBOARDEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/UpdateableGameComponent.h>
#   include <Halak/KeyboardState.h>

    namespace Halak
    {
        class UIKeyboardEventDispatcher : public UpdateableGameComponent
        {
            HKClassFOURCC('U', 'I', 'K', 'B');
            public:
                UIKeyboardEventDispatcher();
                virtual ~UIKeyboardEventDispatcher();

                virtual void Update(float dt, uint timestamp);

                inline UIDomain* GetDomain() const;
                void SetDomain(UIDomain* value);

                inline Keyboard* GetDevice() const;
                void SetDevice(Keyboard* value);

            private:
                UIDomain* domain;
                Keyboard* device;
                KeyboardState lastState;
        };
    }

#   include <Halak/UIKeyboardEventDispatcher.inl>

#endif
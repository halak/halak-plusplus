#pragma once
#ifndef __HALAK_UIKEYBOARDEVENTDISPATCHER_H__
#define __HALAK_UIKEYBOARDEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/KeyboardState.h>

    namespace Halak
    {
        class UIKeyboardEventDispatcher : public GameComponent, public IUpdateable
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

                virtual IUpdateable* QueryUpdateableInterface();

            private:
                uint lastTimestamp;
                UIDomain* domain;
                Keyboard* device;
                KeyboardState lastState;
        };
    }

#   include <Halak/UIKeyboardEventDispatcher.inl>

#endif
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

                ITargetWindow* GetTargetWindow() const;
                void SetTargetWindow(ITargetWindow* value);

                inline Keyboard* GetDevice() const;
                void SetDevice(Keyboard* value);

                virtual IUpdateable* QueryUpdateableInterface();

            private:
                uint lastTimestamp;
                ITargetWindow* targetWindow;
                Keyboard* device;
                KeyboardState lastState;
        };
    }

#   include <Halak/UIKeyboardEventDispatcher.inl>

#endif
#pragma once
#ifndef __HALAK_UIMOUSEEVENTDISPATCHER_H__
#define __HALAK_UIMOUSEEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/MouseState.h>

    namespace Halak
    {
        class UIMouseEventDispatcher : public GameComponent, public IUpdateable
        {
            HKClassFOURCC('U', 'I', 'M', 'S');
            public:
                UIMouseEventDispatcher();
                virtual ~UIMouseEventDispatcher();

                virtual void Update(float dt, uint timestamp);

                inline UIDomain* GetDomain() const;
                void SetDomain(UIDomain* value);

                inline Mouse* GetDevice() const;
                void SetDevice(Mouse* value);

                virtual IUpdateable* QueryUpdateableInterface();

            private:
                uint lastTimestamp;
                UIDomain* domain;
                Mouse* device;

                UIWindowPtr capturedWindow;
                UIWindowPtr lastTargetWindow;
                MouseState  lastMouseState;
        };
    }

#   include <Halak/UIMouseEventDispatcher.inl>

#endif
#pragma once
#ifndef __HALAK_UIMOUSEEVENTDISPATCHER_H__
#define __HALAK_UIMOUSEEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class UIMouseEventDispatcher : public GameComponent, public IUpdateable
        {
            HKClassFOURCC('U', 'I', 'M', 'S');
            public:
                UIMouseEventDispatcher();
                virtual ~UIMouseEventDispatcher();

                virtual void Update(float dt, uint timestamp);

                Mouse* GetDevice() const;
                void SetDevice(Mouse* value);

                virtual IUpdateable* AcquireUpdateableInterface();

            private:
                Mouse* device;
                uint lastTimestamp;
        };
    }

#   include <Halak/UIMouseEventDispatcher.inl>

#endif
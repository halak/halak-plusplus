#pragma once
#ifndef __HALAK_TIMER_H__
#define __HALAK_TIMER_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class Timer : public SharedObject, public IUpdateable
        {
            public:
                Timer();
                Timer(float duration);
                virtual ~Timer();

                virtual void Update(float dt, uint timestamp);

                inline float GetTime() const;
                inline float GetDuration() const;
                void  SetDuration(float value);

            protected:
                virtual void OnTick() = 0;

            private:
                float time;
                float duration;
                uint lastTimestamp;
        };
    }

#   include <Halak/Timer.h>

#endif
#include <Halak/Timer.h>
#include <Halak/Math.h>

namespace Halak
{
    Timer::Timer()
        : time(0.0f),
          duration(0.0f),
          lastTimestamp(0xFFFFFFFF)
    {
    }

    Timer::Timer(float duration)
        : time(0.0f),
          duration(std::max(duration, 0.0f))
    {
    }

    Timer::~Timer()
    {
    }

    void Timer::Update(float dt, uint timestamp)
    {
        if (timestamp == lastTimestamp || time == duration)
            return;

        lastTimestamp = timestamp;

        time += dt;

        if (time >= duration)
        {
            time = duration;
            OnTick();
        }
    }

    void Timer::SetDuration(float value)
    {
        duration = Math::Max(value, 0.0f);
    }
}
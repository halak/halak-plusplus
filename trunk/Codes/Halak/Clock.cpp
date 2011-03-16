#include <Halak/PCH.h>
#include <Halak/Clock.h>

namespace Halak
{
    Clock::Clock()
    {
    }

    Clock::Clock(uint id)
        : GameComponent(id)
    {
    }

    Clock::~Clock()
    {
    }
}
#include <Halak/PCH.h>
#include <Halak/Logger.h>

namespace Halak
{
    Logger::Logger()
    {
    }

    Logger::Logger(uint id)
        : GameComponent(id)
    {
    }

    Logger::~Logger()
    {
    }
}
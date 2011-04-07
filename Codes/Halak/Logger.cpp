#include <Halak/PCH.h>
#include <Halak/Logger.h>

namespace Halak
{
    Logger::Logger()
    {
    }

    Logger::Logger(uint32 id)
        : GameComponent(id)
    {
    }

    Logger::~Logger()
    {
    }
}
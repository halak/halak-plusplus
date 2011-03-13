#include <Halak/CommandQueue.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void CommandQueue::__Startup__()
    {
        Class<CommandQueue>()
            .SetID(HKMakeFOURCC('C', 'M', 'Q', 'E'), "Halak", "CommandQueue")
            .Inherits<GameComponent>();
    }
}
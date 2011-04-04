#include <Halak.Toolkit/PCH.h>
#include <Halak/CommandQueue.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void CommandQueue::__Startup__()
    {
        Class<CommandQueue>()
            .SetID(HKMakeFOURCC('C', 'M', 'Q', 'E'), "Halak", "CommandQueue")
            .Inherits<GameComponent>();
    }
}
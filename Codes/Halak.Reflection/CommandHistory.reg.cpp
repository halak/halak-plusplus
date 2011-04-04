#include <Halak.Toolkit/PCH.h>
#include <Halak/CommandHistory.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void CommandHistory::__Startup__()
    {
        Class<CommandHistory>()
            .SetID(HKMakeFOURCC('C', 'M', 'H', 'S'), "Halak", "CommandHistory")
            .Inherits<GameComponent>();
    }
}
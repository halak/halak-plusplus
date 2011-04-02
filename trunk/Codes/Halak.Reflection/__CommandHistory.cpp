#include <Halak/CommandHistory.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void CommandHistory::__Startup__()
    {
        Class<CommandHistory>()
            .SetID(HKMakeFOURCC('C', 'M', 'H', 'S'), "Halak", "CommandHistory")
            .Inherits<GameComponent>();
    }
}
#include <Halak/Command.h>
#include <Halak/Attributes.h>
#include <Halak/FOURCC.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void Command::__Startup__()
    {
        Class<Command>()
            .SetID(HKMakeFOURCC('C', 'O', 'M', 'D'), "Halak", "Command");
    }
}
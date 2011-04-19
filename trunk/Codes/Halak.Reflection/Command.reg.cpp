#include <Halak.Toolkit/PCH.h>
#include <Halak/Command.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void Command::__Startup__()
    {
        Class<Command>()
            .SetID(HKMakeFOURCC('C', 'O', 'M', 'D'), "Halak", "Command");
    }
}
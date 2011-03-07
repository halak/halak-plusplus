#include <Halak/ChangePropertyCommand.h>
#include <Halak/Attributes.h>
#include <Halak/FOURCC.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void ChangePropertyCommand::__Startup__()
    {
        Class<ChangePropertyCommand>()
            .SetID(HKMakeFOURCC('C', 'P', 'C', 'M'), "Halak", "ChangePropertyCommand")
            .Inherits<RestorableCommand>()
            .Inherits<ICloneable>();
    }
}
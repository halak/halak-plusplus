#include <Halak/BatchCommand.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void BatchCommand::__Startup__()
    {
        Class<BatchCommand>()
            .SetID(HKMakeFOURCC('B', 'A', 'C', 'M'), "Halak", "BatchCommand")
            .Inherits<RestorableCommand>()
            .Inherits<ICloneable>();
    }
}
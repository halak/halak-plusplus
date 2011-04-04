#include <Halak.Toolkit/PCH.h>
#include <Halak/BatchCommand.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

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
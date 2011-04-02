#include <Halak.Toolkit/ChangePropertyCommand.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>

namespace Halak
{
    namespace Toolkit
    {
        void ChangePropertyCommand::__Startup__()
        {
            Class<ChangePropertyCommand>()
                .SetID(HKMakeFOURCC('C', 'P', 'C', 'M'), "Halak", "ChangePropertyCommand")
                .Inherits<RestorableCommand>()
                .Inherits<ICloneable>();
        }
    }
}
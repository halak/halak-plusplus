#include <Halak/PCH.h>
#include <Halak/Command.h>

namespace Halak
{
    Command::Command()
    {
    }

    Command::~Command()
    {
    }

    bool Command::IsRestorable() const
    {
        return false;
    }
}
#include <Halak/PCH.h>
#include <Halak/RestorableCommand.h>

namespace Halak
{
    RestorableCommand::RestorableCommand()
    {
    }

    RestorableCommand::~RestorableCommand()
    {
    }

    void RestorableCommand::Redo()
    {
        Execute();
    }

    bool RestorableCommand::CanUndo() const
    {
        return true;
    }

    bool RestorableCommand::CanRedo() const
    {
        return true;
    }
}
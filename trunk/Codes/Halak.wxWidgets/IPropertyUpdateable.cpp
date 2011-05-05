#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/IPropertyUpdateable.h>
#include <Halak.Toolkit/ChangePropertyCommand.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak/Any.h>
#include <Halak/BatchCommand.h>
#include <Halak/CommandHistory.h>

namespace Halak
{
    namespace wxWidgets
    {
        void IPropertyUpdateable::UpdateTo(CommandHistory* history, const AnyPtrCollection& targets, const PropertyInfo* propertyInfo, const Any& value)
        {
            if (targets.empty())
                return;

            if (history)
            {
                BatchCommand::CommandCollection commands;
                for (AnyPtrCollection::const_iterator it = targets.begin(); it != targets.end(); it++)
                    commands.push_back(new ChangePropertyCommand(*it, propertyInfo, value));

                if (commands.empty() == false)
                {
                    //if (commands.size() == 1)
                    //    history->Execute(commands.front());
                    //else
                        history->Execute(new BatchCommand(commands));
                }
            }
            else
            {
                for (AnyPtrCollection::const_iterator it = targets.begin(); it != targets.end(); it++)
                    propertyInfo->SetValue(*it, value);
            }
        }
    }
}
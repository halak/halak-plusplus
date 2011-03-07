#include <Halak.wxToolkit/IPropertyUpdateable.h>
#include <Halak/Any.h>
#include <Halak/BatchCommand.h>
#include <Halak/ChangePropertyCommand.h>
#include <Halak/CommandHistory.h>
#include <Halak/PropertyInfo.h>

namespace Halak
{
    namespace wxToolkit
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
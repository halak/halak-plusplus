#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/ChangePropertyCommand.h>
#include <Halak.Toolkit/PropertyInfo.h>

namespace Halak
{
    namespace Toolkit
    {
        ChangePropertyCommand::ChangePropertyCommand(const AnyPtr& target, const PropertyInfo* propertyInfo, const Any& value)
            : target(target),
              propertyInfo(propertyInfo),
              newValue(value)
        {
            oldValue = propertyInfo->GetValue(target);
        }

        ChangePropertyCommand::~ChangePropertyCommand()
        {
        }

        void ChangePropertyCommand::Execute()
        {
            propertyInfo->SetValue(target, newValue);
        }

        void ChangePropertyCommand::Undo()
        {
            propertyInfo->SetValue(target, oldValue);
        }

        const AnyPtr& ChangePropertyCommand::GetTargetPointee() const
        {
            return target;
        }

        const PropertyInfo* ChangePropertyCommand::GetPropertyInfo() const
        {
            return propertyInfo;
        }

        const Any& ChangePropertyCommand::GetOldValue() const
        {
            return oldValue;
        }

        const Any& ChangePropertyCommand::GetNewValue() const
        {
            return newValue;
        }
    }
}
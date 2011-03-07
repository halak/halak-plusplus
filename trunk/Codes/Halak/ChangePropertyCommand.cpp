#include <Halak/ChangePropertyCommand.h>
#include <Halak/PropertyInfo.h>

namespace Halak
{
    ChangePropertyCommand::ChangePropertyCommand(const AnyPtr& target, const PropertyInfo* propertyInfo, const Any& value)
        : target(target),
          propertyInfo(propertyInfo),
          newValue(value)
    {
        oldValue = propertyInfo->GetValue(target);
    }

    ChangePropertyCommand::ChangePropertyCommand(const ChangePropertyCommand& original, CloningContext& /*context*/)
        : target(original.target),
          propertyInfo(original.propertyInfo),
          newValue(original.newValue),
          oldValue(original.oldValue)
    {
    }

    ChangePropertyCommand::~ChangePropertyCommand()
    {
    }

    ChangePropertyCommand* ChangePropertyCommand::CloneWith(CloningContext& context) const
    {
        return new ChangePropertyCommand(*this, context);
    }

    void ChangePropertyCommand::Execute()
    {
        propertyInfo->SetValue(target, newValue);
    }

    void ChangePropertyCommand::Undo()
    {
        propertyInfo->SetValue(target, oldValue);
    }

    const AnyPtr& ChangePropertyCommand::GetTarget() const
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
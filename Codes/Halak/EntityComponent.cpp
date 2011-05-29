#include <Halak/PCH.h>
#include <Halak/EntityComponent.h>
#include <Halak/SharedObject.h>

namespace Halak
{
    const EntityComponent EntityComponent::Empty;

    EntityComponent::EntityComponent()
        : name(),
          tag(),
          object(nullptr),
          objectLifetime(),
          operator_(nullptr)
    {
    }

    EntityComponent::EntityComponent(const String& name, const String& tag, void* object, ObjectOperator* operator_)
        : name(name),
          tag(tag),
          object(object),
          objectLifetime(),
          operator_(operator_)
    {
    }

    EntityComponent::EntityComponent(const String& name, const String& tag, SharedObject* object, ObjectOperator* operator_)
        : name(name),
          tag(tag),
          object(object),
          objectLifetime(object),
          operator_(operator_)
    {
    }

    EntityComponent::EntityComponent(const EntityComponent& original)
        : name(original.name),
          tag(original.tag),
          object(original.object),
          objectLifetime(original.objectLifetime),
          operator_(original.operator_)
    {
    }

    EntityComponent::~EntityComponent()
    {
    }

    EntityComponent& EntityComponent::operator = (const EntityComponent& right)
    {
        if (this == &right)
            return *this;

        name = right.name;
        tag = right.tag;
        object = right.object;
        objectLifetime = right.objectLifetime;
        operator_ = right.operator_;

        return *this;
    }

    bool EntityComponent::operator == (const EntityComponent& right) const
    {
        return (name == right.name &&
                tag == right.tag &&
                object == right.object &&
                objectLifetime == right.objectLifetime &&
                operator_ == right.operator_);
    }
}
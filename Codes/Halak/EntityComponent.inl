namespace Halak
{
    const String& EntityComponent::GetName() const
    {
        return name;
    }

    const String& EntityComponent::GetTag() const
    {
        return tag;
    }

    void* EntityComponent::GetObject() const
    {
        return object;
    }

    ObjectOperator* EntityComponent::GetOperator() const
    {
        return operator_;
    }

    bool EntityComponent::operator != (const EntityComponent& right) const
    {
        return !operator == (right);
    }
}
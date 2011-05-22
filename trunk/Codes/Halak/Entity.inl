namespace Halak
{
    const String& Entity::GetName() const
    {
        return name;
    }

    const Entity::ComponentCollection& Entity::GetComponents() const
    {
        return components;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Entity::Component::operator != (const Component& right) const
    {
        return !operator == (right);
    }
}
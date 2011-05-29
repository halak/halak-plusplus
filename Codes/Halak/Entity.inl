namespace Halak
{
    const String& Entity::GetType() const
    {
        return type;
    }

    void Entity::SetType(const String& value)
    {
        type = value;
    }

    const String& Entity::GetName() const
    {
        return name;
    }

    void Entity::SetName(const String& value)
    {
        name = value;
    }

    const Entity::ComponentCollection& Entity::GetIndexedComponents() const
    {
        return indexedComponents;
    }

    const Entity::ComponentCollection& Entity::GetComponents() const
    {
        return components;
    }
}
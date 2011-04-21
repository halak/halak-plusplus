namespace Halak
{
    const String& Entity::GetName() const
    {
        return name;
    }

    Signal<Entity*, const String&>& Entity::NameChangedEvent()
    {
        return nameChangedEvent;
    }
}
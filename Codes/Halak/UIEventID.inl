namespace Halak
{
    UIEventID::UIEventID()
        : type(OtherType)
    {
    }

    UIEventID::UIEventID(Type type)
        : type(type),
          name(ConvertFromTypeToName(type))
    {
    }

    UIEventID::UIEventID(const String& name)
        : type(ConvertFromNameToType(name)),
          name(name)
    {
    }

    UIEventID::UIEventID(const UIEventID& original)
        : type(original.type),
          name(original.name)
    {
    }

    UIEventID::~UIEventID()
    {
    }

    UIEventID::Type UIEventID::GetType() const
    {
        return type;
    }

    const String& UIEventID::GetName() const
    {
        return name;
    }

    UIEventID& UIEventID::operator = (const UIEventID& right)
    {
        type = right.type;
        name = right.name;
        return *this;
    }

    bool UIEventID::operator == (const UIEventID& right) const
    {
        if (type != OtherType)
            return type == right.type;
        else
            return type == right.type && name == right.name;
    }

    bool UIEventID::operator != (const UIEventID& right) const
    {
        return !operator == (right);
    }
}
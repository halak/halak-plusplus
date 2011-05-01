namespace Halak
{
    Colors::NamedColor::NamedColor()
        : Name(nullptr),
          Color(0, 0, 0, 0)
    {
    }

    Colors::NamedColor::NamedColor(const char* name, Color color)
        : Name(name),
          Color(color)
    {
    }

    Colors::NamedColor::NamedColor(const NamedColor& original)
        : Name(original.Name),
          Color(original.Color)          
    {
    }

    Colors::NamedColor& Colors::NamedColor::operator = (const NamedColor& right)
    {
        Name = right.Name;
        Color = right.Color;
    }

    bool Colors::NamedColor::operator == (const NamedColor& right) const
    {
        return Name == right.Name && Color == right.Color;
    }

    bool Colors::NamedColor::operator != (const NamedColor& right) const
    {
        return !operator == (right);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const NamedColorCollection& Colors::GetNamedColors()
    {
        return namedColors;
    }
}
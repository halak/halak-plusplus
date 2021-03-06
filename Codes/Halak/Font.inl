namespace Halak
{
    FontLibrary* Font::GetLibrary() const
    {
        return library;
    }

    Color Font::GetColor() const
    {
        return color;
    }

    Color Font::GetStrokeColor() const
    {
        return strokeColor;
    }

    Color Font::GetGlowColor() const
    {
        return glowColor;
    }

    float Font::GetSpacing() const
    {
        return spacing;
    }

    uint Font::GetRevision() const
    {
        return revision;
    }
}
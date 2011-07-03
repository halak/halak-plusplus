namespace Halak
{
    uint32 TypingContext::GetCode() const
    {
        return currentGlyph ? currentGlyph->GetCode() : '\0';
    }

    Vector2 TypingContext::GetPosition() const
    {
        return currentPosition;
    }
    const Glyph* TypingContext::GetRegularGlyph() const
    {
        return currentGlyph;
    }

    const Glyph* TypingContext::GetStrokedGlyph() const
    {
        return currentStrokedGlyph;
    }

    int TypingContext::GetIndex() const
    {
        return currentIndexFromOriginalText;
    }
}
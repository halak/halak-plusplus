namespace Halak
{
    const String& UIMarkupText::GetOriginalText() const
    {
        return originalText;
    }

    const String& UIMarkupText::GetDisplayText() const
    {
        return displayText;
    }

    const UIMarkupText::PhraseCollection& UIMarkupText::GetPhrases() const
    {
        return phrases;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const String& UIMarkupText::Phrase::GetText() const
    {
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Color* UIMarkupText::ColorPhrase::GetColor() const
    {
        return color;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const String& UIMarkupText::ContentPhrase::GetType() const
    {
        return type;
    }

    const String& UIMarkupText::ContentPhrase::GetName() const
    {
        return name;
    }

    const UIMarkupText::ContentPhrase::Dictionary UIMarkupText::ContentPhrase::GetAttributes() const
    {
        return attributes;
    }
}
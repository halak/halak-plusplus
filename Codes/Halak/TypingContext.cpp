#include <Halak/PCH.h>
#include <Halak/TypingContext.h>
#include <Halak/Internal/GlyphTable.h>
#include <Halak/Assert.h>
#include <Halak/Font.h>
#include <Halak/FontString.h>
#include <Halak/Glyph.h>
#include <Halak/String.h>
#include <windows.h>

namespace Halak
{
    TypingContext::TypingContext(FontPtr font, const String& text, float boundary)
        : fontString(new FontString(font, text)),
          fontStringLocalAllocated(true),
          boundary(boundary),
          currentPosition(Vector2::Zero),
          currentGlyph(nullptr),
          currentStrokedGlyph(nullptr),
          currentIndex(0),
          currentIndexFromOriginalText(0)
    {
    }

    TypingContext::TypingContext(const FontString& string, float boundary)
        : fontString(&string),
          fontStringLocalAllocated(false),
          boundary(boundary),
          currentPosition(Vector2::Zero),
          currentGlyph(nullptr),
          currentStrokedGlyph(nullptr),
          currentIndex(0),
          currentIndexFromOriginalText(0)
    {
    }

    TypingContext::~TypingContext()
    {
        if (fontStringLocalAllocated)
            delete fontString;
    }

    void TypingContext::Reset()
    {
        currentPosition = Vector2::Zero;
        currentGlyph = nullptr;
        currentStrokedGlyph = nullptr;
        currentIndex = 0;
        currentIndexFromOriginalText = 0;
    }

    int TypingContext::GetLength(uint32 code)
    {
        const wchar_t wideCharacter = static_cast<wchar_t>(code);
        return WideCharToMultiByte(CP_ACP, 0, &wideCharacter, 1, NULL, 0, NULL, NULL);
    }

    bool TypingContext::MoveNext()
    {
        const float spacing    = fontString->GetFont()->GetSpacing();
        const float lineHeight = fontString->GetFont()->GetLineHeight();

        if (currentGlyph)
        {
            currentPosition += currentGlyph->GetAdvance() * spacing;
            currentIndexFromOriginalText += GetLength(GetCode());
        }

        if (currentIndex >= static_cast<int>(fontString->GetRegularGlyphs().size()))
            return false;

        if (GetCode() == L'\n')
        {
            currentPosition.X = 0.0f;
            currentPosition.Y += lineHeight;
        }

        currentGlyph = fontString->GetRegularGlyphs()[currentIndex];

        if (fontString->GetFont()->GetStrokeSize() > 0)
            currentStrokedGlyph = fontString->GetStrokedGlyphs()[currentIndex];
        else
            currentStrokedGlyph = nullptr;

        currentIndex++;

        if (currentPosition.X + (currentGlyph->GetAdvance().X * spacing) > boundary)
        {
            currentPosition.X = 0.0f;
            currentPosition.Y += lineHeight;
        }

        return true;
    }
}
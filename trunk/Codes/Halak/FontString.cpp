#include <Halak/PCH.h>
#include <Halak/FontString.h>
#include <Halak/Assert.h>
#include <Halak/Font.h>
#include <Halak/Glyph.h>
#include <windows.h>

namespace Halak
{
    const FontString FontString::Empty;

    FontString::FontString()
        : text(String::Empty),
          font(nullptr)
    {
    }

    FontString::FontString(Font* font, const char* text)
        : text(text),
          font(font)
    {
        FillGlyphs();
    }

    FontString::FontString(Font* font, const String& text)
        : text(text),
          font(font)
    {
        FillGlyphs();
    }

    FontString::FontString(const FontString& original)
        : text(original.text),
          font(original.font),
          regularGlyphs(original.regularGlyphs),
          strokedGlyphs(original.strokedGlyphs)
    {
    }

    FontString::~FontString()
    {
    }

    int FontString::ConvertToOriginalIndex(int index) const
    {
        int result = 0;
        for (int i = 0; i < index; i++)
        {
            wchar_t code = regularGlyphs[i]->GetCode();
            result += WideCharToMultiByte(CP_ACP, 0, &code, 1, nullptr, 0, nullptr, nullptr);
        }

        return result;
    }

    const String& FontString::GetOriginal() const
    {
        return text;
    }

    Font* FontString::GetFont() const
    {
        return font;
    }

    const FontString::GlyphCollection& FontString::GetRegularGlyphs() const
    {
        return regularGlyphs;
    }

    const FontString::GlyphCollection& FontString::GetStrokedGlyphs() const
    {
        return strokedGlyphs;
    }

    void FontString::FillGlyphs()
    {
        regularGlyphs.clear();
        strokedGlyphs.clear();

        std::vector<wchar_t> wideCharacters;
        wideCharacters.resize(MultiByteToWideChar(CP_ACP, 0, text.CStr(), text.GetLength(), NULL, 0), L'\0');
        MultiByteToWideChar(CP_ACP, 0, text.CStr(), text.GetLength(), &wideCharacters[0], wideCharacters.size());

        if (font->GetStrokeSize() > 0.0f)
        {
            regularGlyphs.reserve(wideCharacters.size());
            strokedGlyphs.reserve(wideCharacters.size());
            for (std::vector<wchar_t>::const_iterator it = wideCharacters.begin(); it != wideCharacters.end(); it++)
            {
                regularGlyphs.push_back(font->GetRegularGlyph(*it));
                strokedGlyphs.push_back(font->GetStrokedGlyph(*it));
            }
        }
        else
        {
            regularGlyphs.reserve(wideCharacters.size());
            for (std::vector<wchar_t>::const_iterator it = wideCharacters.begin(); it != wideCharacters.end(); it++)
            {
                regularGlyphs.push_back(font->GetRegularGlyph(*it));
            }
        }
    }

    FontString& FontString::operator = (const char* text)
    {
        this->text = text;
        FillGlyphs();
        return *this;
    }

    FontString& FontString::operator = (const String& text)
    {
        this->text = text;
        FillGlyphs();
        return *this;
    }

    FontString& FontString::operator = (const FontString& original)
    {
        text = original.text;
        font = original.font;
        regularGlyphs = original.regularGlyphs;
        strokedGlyphs = original.strokedGlyphs;
        return *this;
    }
}
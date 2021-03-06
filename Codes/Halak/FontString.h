#pragma once
#ifndef __HALAK_FONTSTRING_H__
#define __HALAK_FONTSTRING_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        class FontString
        {
            public:
                typedef std::vector<const Glyph*> GlyphCollection;

            public:
                FontString();
                FontString(Font* font, const char* text);
                FontString(Font* font, const String& text);
                FontString(const FontString& original);
                ~FontString();

                /// Summary:
                /// Glyphs에 Index에 대응하는 Original Text로부터의 Index를 가져옵니다.
                /// 예) "가나다"의 '나'부분은 Glyphs Index는 1이지만 Original Text로부터의 Index는 2입니다.
                int ConvertToOriginalIndex(int index) const;

                inline const String& GetText() const;
                inline Font* GetFont() const;
                inline const GlyphCollection& GetRegularGlyphs() const;
                inline const GlyphCollection& GetStrokedGlyphs() const;
                inline const GlyphCollection& GetGlowGlyphs() const;

                FontString& operator = (const char* text);
                FontString& operator = (const String& text);
                FontString& operator = (const FontString& original);

            public:
                static const FontString Empty;

            private:
                void FillGlyphs();

            private:
                String  text;
                FontPtr font;
                GlyphCollection regularGlyphs;
                GlyphCollection strokedGlyphs;
                GlyphCollection glowGlyphs;
        };
    }

#    include <Halak/FontString.inl>

#endif
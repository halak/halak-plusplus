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
                FontString(FontPtr font, const char* text);
                FontString(FontPtr font, const String& text);
                FontString(const FontString& original);
                ~FontString();

                /// Summary:
                /// Glyphs�� Index�� �����ϴ� Original Text�κ����� Index�� �����ɴϴ�.
                /// ��) "������"�� '��'�κ��� Glyphs Index�� 1������ Original Text�κ����� Index�� 2�Դϴ�.
                int ConvertToOriginalIndex(int index) const;

                const String& GetOriginal() const;
                FontPtr GetFont() const;
                const GlyphCollection& GetRegularGlyphs() const;
                const GlyphCollection& GetStrokedGlyphs() const;

                FontString& operator = (const char* text);
                FontString& operator = (const String& text);
                FontString& operator = (const FontString& original);

            private:
                void FillGlyphs();

            private:
                String  text;
                FontPtr font;
                GlyphCollection regularGlyphs;
                GlyphCollection strokedGlyphs;
        };
    }

#endif
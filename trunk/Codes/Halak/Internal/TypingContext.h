#pragma once
#ifndef __HALAK_TYPINGCONTEXT_H__
#define __HALAK_TYPINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/Vector2.h>
#   include <vector>

    namespace Halak
    {
        class TypingContext
        {
            public:
                TypingContext(FontPtr font, const String& text, float boundary);
                TypingContext(const FontString& string, float boundary);
                ~TypingContext();

                void Reset();
                bool MoveNext();

                wchar_t        GetCode() const;
                Vector2 GetPosition() const;
                const Glyph*   GetRegularGlyph() const;
                const Glyph*   GetStrokedGlyph() const;
                int            GetIndex() const;

            private:
                static int GetLength(wchar_t code);

            private:
                const FontString* fontString;
                bool fontStringLocalAllocated;

                float boundary;

                Vector2 currentPosition;
                const Glyph*   currentGlyph;
                const Glyph*   currentStrokedGlyph;
                int            currentIndex;
                int            currentIndexFromOriginalText;

            private:
                TypingContext(const TypingContext&);
                TypingContext& operator = (const TypingContext&);
        };
    }

#endif
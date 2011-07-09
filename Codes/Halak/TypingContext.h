#pragma once
#ifndef __HALAK_TYPINGCONTEXT_H__
#define __HALAK_TYPINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/Glyph.h>
#   include <Halak/Vector2.h>
#   include <vector>

    namespace Halak
    {
        class TypingContext
        {
            public:
                TypingContext(Font* font, const String& text, float boundary);
                TypingContext(const FontString& string, float boundary);
                ~TypingContext();

                void Reset();
                bool MoveNext();

                inline uint32 GetCode() const;
                inline Vector2 GetPosition() const;
                inline const Glyph* GetRegularGlyph() const;
                inline const Glyph* GetStrokedGlyph() const;
                inline int GetIndex() const;
                inline int GetGlyphIndex() const;

            private:
                static inline int GetLength(uint32 code);

            private:
                const FontString* fontString;
                bool fontStringLocalAllocated;

                float boundary;

                Vector2 currentPosition;
                const Glyph* currentGlyph;
                const Glyph* currentStrokedGlyph;
                int currentIndex;
                int currentIndexFromOriginalText;

            private:
                TypingContext(const TypingContext&);
                TypingContext& operator = (const TypingContext&);
        };
    }

#   include <Halak/TypingContext.inl>

#endif
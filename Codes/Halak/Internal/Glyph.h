#pragma once
#ifndef __HALAK_GLYPH_H__
#define __HALAK_GLYPH_H__

#   include <Halak/FWD.h>
#   include <Halak/Rectangle.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class Glyph
        {
            friend class GlyphTable;
            public:
                inline wchar_t GetCode() const;
                inline Vector2 GetAdvance() const;
                inline Vector2 GetBitmapOffset() const;
                inline Vector2 GetBitmapSize() const;
                inline GlyphSurface* GetSurface() const;
                inline Texture2DPtr GetTexture() const;
                inline Rectangle GetClippingRectangle() const;

            private:
                Glyph(wchar_t code, Vector2 advance);
                Glyph(wchar_t code, Vector2 advance, Vector2 bitmapOffset, Vector2 bitmapSize, GlyphSurface* surface, Rectangle clippingRectangle);
                ~Glyph();

            private:
                wchar_t code;
                Vector2 advance;
                Vector2 bitmapOffset;
                Vector2 bitmapSize;
                GlyphSurface* surface;
                Texture2DPtr texture;
                Rectangle clippingRectangle;

            private:
                Glyph(const Glyph&);
                Glyph& operator = (const Glyph&);
        };
    }

#   include <Halak/Internal/Glyph.inl>

#endif
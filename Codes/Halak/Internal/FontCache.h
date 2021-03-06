#pragma once
#ifndef __HALAK_FONTCACHE_H__
#define __HALAK_FONTCACHE_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/String.h>
#   include <ft2build.h>
#   include FT_FREETYPE_H
#   include FT_STROKER_H
#   include FT_BITMAP_H

    namespace Halak
    {
        struct FontCacheParameters
        {
            String Face;
            float FontSize;
            float StrokeSize;
            float Weights;
            float Shear;
            int GlowSize;
            float GlowSpread;
            float GlowThickness;
            float Scale;
            bool Hinting;
            bool IgnoreBitmap;

            FontCacheParameters();
            FontCacheParameters(const String& face, float fontSize, float strokeSize, float weights, float shear, 
                                int glowSize, float glowSpread, float glowThickness,
                                float scale, bool hinting, bool ignoreBitmap);

            unsigned int GetHashCode() const;

            bool operator == (const FontCacheParameters& right) const;
            inline bool operator != (const FontCacheParameters& right) const;
        };

        class FontCache : public Asset
        {
            public:
                virtual ~FontCache();

                const Glyph* GetGlyph(uint32 code);

                inline FontLibrary* GetLibrary() const;
                inline const FontCacheParameters& GetParameters() const;
                inline float GetAscender() const;
                inline float GetDescender() const;
                inline float GetLineHeight() const;

                inline const GlyphTable* GetRegularGlyphTable() const;
                inline const GlyphTable* GetStrokedGlyphTable() const;
                inline const GlyphTable* GetGlowGlyphTable() const;

            private:
                FontCache(FontLibrary* library, const FontCacheParameters& parameters);

            private:
                FontLibrary* library;
                FontCacheParameters parameters;

                FT_Face primaryFace;
                FT_Face alternativeFace;
                FT_Stroker stroker;
                FT_Matrix transform;

                float ascender;
                float descender;
                float lineHeight;

                GlyphTable* regularGlyphTable;
                GlyphTable* strokedGlyphTable;
                GlyphTable* glowGlyphTable;

                friend class FontLibrary;
        };
    }

#    include <Halak/Internal/FontCache.inl>

#endif
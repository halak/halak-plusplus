#pragma once
#ifndef __HALAK_FREETYPEFONTRENDERER_H__
#define __HALAK_FREETYPEFONTRENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/String.h>
#   include <ft2build.h>
#   include FT_FREETYPE_H
#   include FT_STROKER_H
#   include FT_BITMAP_H

    namespace Halak
    {
        struct FreeTypeFontRendererParameters
        {
            String Face;
            float FontSize;
            float StrokeSize;
            float Weights;
            float Shear;
            float Scale;
            bool Hinting;
            bool IgnoreBitmap;

            FreeTypeFontRendererParameters();
            FreeTypeFontRendererParameters(const String& face, float size);
            FreeTypeFontRendererParameters(const String& face, float fontSize, float strokeSize, float weights, float shear, float scale, bool hinting, bool ignoreBitmap);
            FreeTypeFontRendererParameters(const String& face, float fontSize, float strokeSize, bool bold, bool italic, float scale, bool hinting, bool ignoreBitmap);

            unsigned int GetHashCode() const;

            bool operator == (const FreeTypeFontRendererParameters& right) const;
            bool operator != (const FreeTypeFontRendererParameters& right) const;
        };

        class FreeTypeFontRenderer : public Asset
        {
            friend class FreeType;
            public:
                virtual ~FreeTypeFontRenderer();

                const Glyph* GetGlyph(wchar_t code);

                FreeType* GetFreeType() const;
                const FreeTypeFontRendererParameters& GetParameters() const;
                float GetAscender() const;
                float GetDescender() const;
                float GetLineHeight() const;

                const GlyphTable* GetRegularGlyphTable() const;
                const GlyphTable* GetStrokedGlyphTable() const;

            private:
                FreeTypeFontRenderer(FreeType* freeType, const FreeTypeFontRendererParameters& parameters);

            private:
                FreeType* freeType;
                FreeTypeFontRendererParameters parameters;

                FT_Face primaryFace;
                FT_Face alternativeFace;
                FT_Stroker stroker;
                FT_Matrix transform;

                float ascender;
                float descender;
                float lineHeight;

                GlyphTable* regularGlyphTable;
                GlyphTable* strokedGlyphTable;
        };
    }

#endif
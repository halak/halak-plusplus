#pragma once
#ifndef __HALAK_GLYPHTABLE_H__
#define __HALAK_GLYPHTABLE_H__

#   include <Halak/FWD.h>
#   include <Halak/Point.h>
#   include <Halak/Vector2.h>
#   include <map>
#   include <vector>

    namespace Halak
    {
        class GlyphTable
        {
            public:
                typedef std::map<uint32, const Glyph*> GlyphDictionary;
                typedef std::vector<GlyphSurface*> SurfaceCollection;

            public:
                GlyphTable(GraphicsDevice* graphicsDevice);
                ~GlyphTable();

                const Glyph* Add(uint32 code, Vector2 advance, Vector2 bitmapOffset, Vector2 bitmapSize, const void* buffer, int width, int height, int pitch);

                bool Remove(uint32 code);

                void Clear();

                const Glyph* Find(uint32 code) const;

                inline const GlyphDictionary& GetGlyphs() const;
                inline const SurfaceCollection& GetSurfaces() const;

            private:
                std::pair<GlyphSurface*, Rectangle> AllocateSurface(const void* buffer, int width, int height, int pitch);
                static Point GetAdaptiveSurfaceSize(int numberOfExisting, int width, int height);

            private:
                GraphicsDevice* graphicsDevice;
                GlyphDictionary glyphs;
                SurfaceCollection surfaces;

            private:
                GlyphTable(const GlyphTable&);
                GlyphTable& operator = (const GlyphTable&);
        };
    }

#   include <Halak/Internal/GlyphTable.inl>

#endif
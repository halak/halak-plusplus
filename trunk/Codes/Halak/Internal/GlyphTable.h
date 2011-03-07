#pragma once
#ifndef __HALAK_GLYPHTABLE_H__
#define __HALAK_GLYPHTABLE_H__

#   include <Halak/FWD.h>
#   include <Halak/Point.h>
#   include <Halak/Vector2.h>
#   include <list>
#   include <map>

    namespace Halak
    {
        class GlyphTable
        {
            public:
                typedef std::map<wchar_t, const Glyph*> GlyphDictionary;
                typedef std::list<GlyphSurface*> SurfaceCollection;

            public:
                GlyphTable(GraphicsDevice* graphicsDevice);
                ~GlyphTable();

                const Glyph* Add(wchar_t code, Vector2 advance, Vector2 bitmapOffset, Vector2 bitmapSize, const void* buffer, int width, int height, int pitch);

                bool Remove(wchar_t code);

                void Clear();

                const Glyph* Find(wchar_t code) const;

                const SurfaceCollection& GetSurfaces() const;

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

#endif
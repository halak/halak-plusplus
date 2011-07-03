#include <Halak/PCH.h>
#include <Halak/Glyph.h>
#include <Halak/Internal/GlyphSurface.h>
#include <Halak/Texture2D.h>

namespace Halak
{
    Glyph::Glyph(uint32 code, Vector2 advance)
        : code(code),
          advance(advance),
          bitmapOffset(Vector2::Zero),
          bitmapSize(Vector2::Zero),
          surface(nullptr),
          clippingRectangle(Rectangle::Empty)
    {
    }

    Glyph::Glyph(uint32 code, Vector2 advance, Vector2 bitmapOffset, Vector2 bitmapSize, GlyphSurface* surface, Rectangle clippingRectangle)
        : code(code),
          advance(advance),
          bitmapOffset(bitmapOffset),
          bitmapSize(bitmapSize),
          surface(surface),
          texture(surface->GetTexture()),
          clippingRectangle(clippingRectangle)
    {
    }

    Glyph::~Glyph()
    {
        if (surface)
            surface->Deallocate(clippingRectangle);
    }
}
namespace Halak
{
    uint32 Glyph::GetCode() const
    {
        return code;
    }

    Vector2 Glyph::GetAdvance() const
    {
        return advance;
    }

    Vector2 Glyph::GetBitmapOffset() const
    {
        return bitmapOffset;
    }

    Vector2 Glyph::GetBitmapSize() const
    {
        return bitmapSize;
    }

     GlyphSurface* Glyph::GetSurface() const
     {
         return surface;
     }

    Texture2D* Glyph::GetTexture() const
    {
        return texture;
    }

    Rectangle Glyph::GetClippingRectangle() const
    {
        return clippingRectangle;
    }
}
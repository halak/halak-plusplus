namespace Halak
{
    const String& UIImage::GetTextureURI() const
    {
        return textureURI;
    }

    const Rectangle& UIImage::GetClippingRectangle() const
    {
        return clippingRectangle;
    }

    const Texture2DPtr& UIImage::GetRealTexture() const
    {
        return realTexture;
    }

    const Rectangle& UIImage::GetRealClippingRectangle() const
    {
        return realClippingRectangle;
    }

    const RectangleF& UIImage::GetNormalizedRealClippingRectangle() const
    {
        return normalizedRealClippingRectangle;
    }

    uint UIImage::GetRevision() const
    {
        return revision;
    }
}
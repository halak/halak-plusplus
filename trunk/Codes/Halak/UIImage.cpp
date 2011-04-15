#include <Halak/PCH.h>
#include <Halak/UIImage.h>
#include <Halak/Texture2D.h>

namespace Halak
{
    UIImage::UIImage(const String& textureURI, const Rectangle& clippingRectangle)
        : textureURI(textureURI),
          clippingRectangle(clippingRectangle),
          revision(1)
    {
    }

    UIImage::~UIImage()
    {
    }

    void UIImage::SetRealTextureData(const Texture2DPtr& texture, const Rectangle& clippingRectangle)
    {
        if (realTexture != texture || realClippingRectangle != clippingRectangle)
        {
            realTexture = texture;
            realClippingRectangle = clippingRectangle;
            
            if (texture)
            {
                const float textureWidth  = static_cast<float>(texture->GetWidth());
                const float textureHeight = static_cast<float>(texture->GetHeight());
                const float left   = static_cast<float>(clippingRectangle.GetLeft()) / textureWidth;
                const float top    = static_cast<float>(clippingRectangle.GetTop()) / textureHeight;
                const float right  = static_cast<float>(clippingRectangle.GetRight()) / textureWidth;
                const float bottom = static_cast<float>(clippingRectangle.GetBottom()) / textureHeight;
                normalizedRealClippingRectangle = RectangleF(left, top, right - left, bottom - top);
            }
            else
                normalizedRealClippingRectangle = RectangleF::Empty;

            revision++;
        }
    }
}
#include <Halak/PCH.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/Font.h>
#include <Halak/FontString.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/UIImage.h>
#include <Halak/UIVisual.h>

#include <Halak/Texture2D.h>

namespace Halak
{
    UIDrawingContext::UIDrawingContext(SpriteRenderer* renderer)
        : renderer(renderer)
    {
    }
    
    UIDrawingContext::~UIDrawingContext()
    {
    }

    void UIDrawingContext::Draw(const RectangleF& bounds, const RectangleF& clippedBounds, UIImage* image, bool horizontalFlip, bool verticalFlip)
    {
        HKAssertDebug(image && image->GetRealTexture());

        const float boundsClippedLeft   = (clippedBounds.GetLeft() - bounds.GetLeft()) / bounds.Width;
        const float boundsClippedTop    = (clippedBounds.GetTop() - bounds.GetTop()) / bounds.Height;
        const float boundsClippedRight  = (bounds.GetRight() - clippedBounds.GetRight()) / bounds.Width;
        const float boundsClippedBottom = (bounds.GetBottom() - clippedBounds.GetBottom()) / bounds.Height;

        RectangleF clippingRectangle = image->GetNormalizedRealClippingRectangle();
        const float clippingLeft   = clippingRectangle.GetLeft() + boundsClippedLeft;
        const float clippingTop    = clippingRectangle.GetTop() + boundsClippedTop;
        const float clippingRight  = clippingRectangle.GetRight() - boundsClippedRight;
        const float clippingBottom = clippingRectangle.GetBottom() - boundsClippedBottom;

        clippingRectangle.X = clippingLeft;
        clippingRectangle.Y = clippingTop;
        clippingRectangle.Width  = (horizontalFlip == false) ? clippingRight - clippingLeft : clippingLeft - clippingRight;
        clippingRectangle.Height = (verticalFlip   == false) ? clippingBottom - clippingTop : clippingTop - clippingBottom;

        const float w = static_cast<float>(image->GetRealTexture()->GetSurfaceWidth());
        const float h = static_cast<float>(image->GetRealTexture()->GetSurfaceHeight());
        Rectangle pixelClippingRectangle = Rectangle::Empty;
        pixelClippingRectangle.X = static_cast<int>(clippingRectangle.X * w);
        pixelClippingRectangle.Y = static_cast<int>(clippingRectangle.Y * h);
        pixelClippingRectangle.Width = static_cast<int>(clippingRectangle.Width * w);
        pixelClippingRectangle.Height = static_cast<int>(clippingRectangle.Height * h);

        Vector2 scale = Vector2::One;
        scale.X = clippedBounds.Width / static_cast<float>(pixelClippingRectangle.Width);
        scale.Y = clippedBounds.Height / static_cast<float>(pixelClippingRectangle.Height);
        renderer->Draw(Vector3(clippedBounds.X, clippedBounds.Y, 0.0f), Vector3::Zero, scale,
                       image->GetRealTexture(), pixelClippingRectangle,
                       Color(Vector4(1.0f, 1.0f, 1.0f, GetCurrentOpacity())));
    }

    void UIDrawingContext::DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, Font* font, const String& text)
    {
        renderer->DrawString(Vector2(clippedBounds.X, clippedBounds.Y), FontString(font, text), static_cast<float>(text.GetLength()), bounds.Width);
    }

    void UIDrawingContext::DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, const FontString& fontString)
    {
        renderer->DrawString(Vector2(clippedBounds.X, clippedBounds.Y), fontString, static_cast<float>(fontString.GetOriginal().GetLength()), bounds.Width);
    }

    void UIDrawingContext::DrawRectangle(const RectangleF& bounds, Color color)
    {
        color.A = static_cast<byte>(static_cast<float>(color.A) * GetCurrentOpacity());
        renderer->DrawRectangle(bounds, color);
    }

    void UIDrawingContext::OnVisit(UIVisual* target)
    {
        target->OnDraw(*this);
    }
}
#include <Halak/PCH.h>
#include <Halak/UIDrawingContext.h>
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

    void UIDrawingContext::Draw(const RectangleF& bounds, UIImage* image, const RectangleF& clippingRectangle)
    {
        const float w = static_cast<float>(image->GetRealTexture()->GetSurfaceWidth());
        const float h = static_cast<float>(image->GetRealTexture()->GetSurfaceHeight());
        Rectangle pixelClippingRectangle = Rectangle::Empty;
        pixelClippingRectangle.X = static_cast<int>(clippingRectangle.X * w);
        pixelClippingRectangle.Y = static_cast<int>(clippingRectangle.Y * h);
        pixelClippingRectangle.Width = static_cast<int>(clippingRectangle.Width * w);
        pixelClippingRectangle.Height = static_cast<int>(clippingRectangle.Height * h);

        Vector2 scale = Vector2::One;
        scale.X = bounds.Width / static_cast<float>(pixelClippingRectangle.Width);
        scale.Y = bounds.Height / static_cast<float>(pixelClippingRectangle.Height);
        renderer->Draw(Vector3(bounds.X, bounds.Y, 0.0f), Vector3::Zero, scale,
                       image->GetRealTexture(), pixelClippingRectangle,
                       Color::White);
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
#include <Halak/PCH.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/UIRenderer.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    UIDrawingContext::UIDrawingContext(UIRenderer* renderer)
        : renderer(renderer)
    {
    }
    
    UIDrawingContext::~UIDrawingContext()
    {
    }

    void UIDrawingContext::Draw(const RectangleF& bounds, UIImage* image, const RectangleF& clippingRectangle)
    {
    }

    void UIDrawingContext::DrawRectangle(const RectangleF& bounds, Color color)
    {
        color.A = static_cast<byte>(static_cast<float>(color.A) * GetCurrentOpacity());
        renderer->GetSpriteRenderer()->DrawRectangle(bounds, color);
    }

    void UIDrawingContext::OnVisit(UIVisual* target)
    {
        target->OnDraw(*this);
    }
}
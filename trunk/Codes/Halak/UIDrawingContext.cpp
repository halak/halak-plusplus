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

    void UIDrawingContext::Draw(const RectangleF& bounds, const UIImagePtr& image, const RectangleF& clippingRectangle)
    {
    }

    void UIDrawingContext::OnVisit(const UIVisualPtr& target)
    {
        target->OnDraw(*this);
    }
}
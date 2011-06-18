#include <Halak/PCH.h>
#include <Halak/UIHandledDrawingContext.h>
#include <Halak/Math.h>

namespace Halak
{
    UIHandledDrawingContext::UIHandledDrawingContext(UIRenderer* renderer)
        : UIDrawingContext(renderer),
          handler(BoundsVisualizer::GetInstance())
    {
    }

    UIHandledDrawingContext::UIHandledDrawingContext(UIRenderer* renderer, IHandler* handler)
        : UIDrawingContext(renderer),
          handler(handler)
    {
    }

    UIHandledDrawingContext::~UIHandledDrawingContext()
    {
    }

    void UIHandledDrawingContext::OnBegan()
    {
        if (handler)
            handler->OnBegan(*this);
    }

    void UIHandledDrawingContext::OnEnded()
    {
        if (handler)
            handler->OnEnded(*this);
    }

    void UIHandledDrawingContext::OnVisit(UIVisual* target)
    {
        if (handler)
        {
            handler->OnDrawBegan(*this, target);
            UIDrawingContext::OnVisit(target);
            handler->OnDrawEnded(*this, target);
        }
        else
            UIDrawingContext::OnVisit(target);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Color UIHandledDrawingContext::BoundsVisualizer::LineColor = Color(255, 255, 255);
    float UIHandledDrawingContext::BoundsVisualizer::LineWidth = 2.0f;

    UIHandledDrawingContext::BoundsVisualizer::BoundsVisualizer()
    {
    }

    UIHandledDrawingContext::BoundsVisualizer::~BoundsVisualizer()
    {
    }

    Color UIHandledDrawingContext::BoundsVisualizer::GetLineColor()
    {
        return LineColor;
    }
    
    void UIHandledDrawingContext::BoundsVisualizer::SetLineColor(Color value)
    {
        LineColor = value;
    }

    float UIHandledDrawingContext::BoundsVisualizer::GetLineWidth()
    {
        return LineWidth;
    }

    void UIHandledDrawingContext::BoundsVisualizer::SetLineWidth(float value)
    {
        LineWidth = Math::Max(value, 0.0f);
    }

    void UIHandledDrawingContext::BoundsVisualizer::OnDrawBegan(UIHandledDrawingContext& context, UIVisual* target)
    {
        context.DrawRectangle(context.GetCurrentBounds(), LineWidth, LineColor);
    }
}
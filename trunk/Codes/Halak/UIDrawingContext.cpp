#include <Halak/PCH.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/Font.h>
#include <Halak/FontString.h>
#include <Halak/UIImage.h>
#include <Halak/UIRenderer.h>
#include <Halak/UIVisual.h>

#include <Halak/Texture2D.h>

namespace Halak
{
    UIDrawingContext::UIDrawingContext(UIRenderer* renderer)
        : UIVisualVisitor(renderer->GetViewTransform(), renderer->GetInversedViewTransform(), renderer->GetProjectionTransform(), true),
          renderer(renderer),
          depth(0)
    {
    }
    
    UIDrawingContext::~UIDrawingContext()
    {
    }

    void UIDrawingContext::Draw(UIVisual* target)
    {
        if (depth == 0)
        {
            renderer->Begin();
            OnBegan();
        }

        depth++;

        Visit(target);

        depth--;
        
        if (depth == 0)
        {
            OnEnded();
            renderer->End();
        }
    }

    void UIDrawingContext::Draw(const RectangleF& bounds, const RectangleF& clippedBounds, UIImage* image, bool horizontalFlip, bool verticalFlip)
    {
        HKAssertDebug(image && image->GetRealTexture() && renderer);

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

        Vector2 points[] =
        {
            Vector2(clippedBounds.GetLeft(),  clippedBounds.GetTop()),
            Vector2(clippedBounds.GetRight(), clippedBounds.GetTop()),
            Vector2(clippedBounds.GetLeft(),  clippedBounds.GetBottom()),
            Vector2(clippedBounds.GetRight(), clippedBounds.GetBottom()),
        };
        Project(points[0], points[1], points[2], points[3]);

        renderer->Draw(points[0], points[1], points[2], points[3], clippingRectangle, image->GetRealTexture(), Color(Vector4(1.0f, 1.0f, 1.0f, GetCurrentOpacity())));
    }

    void UIDrawingContext::DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, Font* font, const String& text)
    {
        //renderer->DrawString(Vector2(clippedBounds.X, clippedBounds.Y), FontString(font, text), static_cast<float>(text.GetLength()), bounds.Width);
    }

    void UIDrawingContext::DrawString(const RectangleF& bounds, const RectangleF& clippedBounds, const FontString& fontString)
    {
        //renderer->DrawString(Vector2(clippedBounds.X, clippedBounds.Y), fontString, static_cast<float>(fontString.GetOriginal().GetLength()), bounds.Width);
    }

    void UIDrawingContext::DrawRectangle(const RectangleF& bounds, float width, Color color)
    {
        color.A = static_cast<byte>(static_cast<float>(color.A) * GetCurrentOpacity());
        //renderer->DrawRectangle(bounds, color);
    }

    void UIDrawingContext::FillRectangle(const RectangleF& bounds, float width, Color color)
    {
        color.A = static_cast<byte>(static_cast<float>(color.A) * GetCurrentOpacity());
    }

    void UIDrawingContext::OnBegan()
    {
    }

    void UIDrawingContext::OnEnded()
    {
    }

    void UIDrawingContext::OnVisit(UIVisual* target)
    {
        target->OnDraw(*this);
    }
}
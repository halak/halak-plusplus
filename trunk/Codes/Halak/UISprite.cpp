#include <Halak/PCH.h>
#include <Halak/UISprite.h>
#include <Halak/Assert.h>
#include <Halak/Color.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFrame.h>
#include <Halak/UIImage.h>

namespace Halak
{
    UISprite::UISprite()
        : image(nullptr),
          autoResize(true),
          horizontalFlip(false),
          verticalFlip(false)
    {
    }

    UISprite::~UISprite()
    {
    }

    void UISprite::SetImage(UIImage* value)
    {
        if (GetImage() != value)
        {
            image = value;

            if (GetAutoResize() && GetImage() && GetFrame() && GetFrame()->IsResizable())
                ResizeToImageSize();
        }
    }

    void UISprite::SetAutoResize(bool value)
    {
        if (GetAutoResize() != value)
        {
            autoResize = value;

            if (GetAutoResize() && GetImage() && GetFrame() && GetFrame()->IsResizable())
                ResizeToImageSize();
        }
    }

    void UISprite::OnDraw(UIDrawingContext& context)
    {
        UIVisual::OnDraw(context);

        context.DrawRectangle(context.GetCurrentBounds(), Color::White);
        context.DrawRectangle(context.GetCurrentClippedBounds(), Color::Yellow);

        if (GetImage() == nullptr || GetImage()->GetRealTexture() == nullptr)
            return;

        const RectangleF bounds = context.GetCurrentBounds();
        const RectangleF clippedBounds = context.GetCurrentClippedBounds();
        const float boundsClippedLeft   = (clippedBounds.GetLeft() - bounds.GetLeft()) / bounds.Width;
        const float boundsClippedTop    = (clippedBounds.GetTop() - bounds.GetTop()) / bounds.Height;
        const float boundsClippedRight  = (bounds.GetRight() - clippedBounds.GetRight()) / bounds.Width;
        const float boundsClippedBottom = (bounds.GetBottom() - clippedBounds.GetBottom()) / bounds.Height;

        RectangleF clippingRectangle = GetImage()->GetNormalizedRealClippingRectangle();
        const float clippingLeft   = clippingRectangle.GetLeft() + boundsClippedLeft;
        const float clippingTop    = clippingRectangle.GetTop() + boundsClippedTop;
        const float clippingRight  = clippingRectangle.GetRight() - boundsClippedRight;
        const float clippingBottom = clippingRectangle.GetBottom() - boundsClippedBottom;

        clippingRectangle.X = clippingLeft;
        clippingRectangle.Y = clippingTop;
        clippingRectangle.Width  = (horizontalFlip == false) ? clippingRight - clippingLeft : clippingLeft - clippingRight;
        clippingRectangle.Height = (verticalFlip   == false) ? clippingBottom - clippingTop : clippingTop - clippingBottom;

        context.Draw(context.GetCurrentClippedBounds(), GetImage(), clippingRectangle);
    }

    void UISprite::ResizeToImageSize()
    {
        HKAssertDebug(GetAutoResize() && GetImage() && GetFrame() && GetFrame()->IsResizable());

        const Rectangle& clippingRectangle = GetImage()->GetClippingRectangle();
        if (clippingRectangle.IsEmpty() == false)
            GetFrame()->ResizeTo(Vector2(clippingRectangle.Width, clippingRectangle.Height));
        else
        {
            const Rectangle& realClippingRectangle = GetImage()->GetRealClippingRectangle();
            if (realClippingRectangle.IsEmpty() == false)
                GetFrame()->ResizeTo(Vector2(realClippingRectangle.Width, realClippingRectangle.Height));
        }
    }
}
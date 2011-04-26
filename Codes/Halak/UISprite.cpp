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

        context.Draw(GetImage(), GetHorizontalFlip(), GetVerticalFlip());
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
#include <Halak/PCH.h>
#include <Halak/UISprite.h>
#include <Halak/Assert.h>
#include <Halak/Colors.h>
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

    RectangleF UISprite::ComputeBounds(UIVisualVisitor& visitor)
    {
        Vector2 desiredSize = Vector2::Zero;

        if (GetAutoResize() && GetImage())
        {
            const Rectangle clippingRectangle = GetImage()->GetClippingRectangle();
            if (clippingRectangle.IsEmpty() == false)
                desiredSize = Vector2(clippingRectangle.Width, clippingRectangle.Height);
            else
            {
                const Rectangle realClippingRectangle = GetImage()->GetRealClippingRectangle();
                desiredSize = Vector2(realClippingRectangle.Width, realClippingRectangle.Width);
            }
        }

        return GetFrame()->ComputeBounds(visitor, desiredSize);
    }

    void UISprite::SetImage(UIImage* value)
    {
        image = value;
    }

    void UISprite::OnDraw(UIDrawingContext& context)
    {
        UIVisual::OnDraw(context);

        if (GetImage() == nullptr || GetImage()->GetRealTexture() == nullptr)
            return;

        context.Draw(GetImage(), GetHorizontalFlip(), GetVerticalFlip());
    }
}
namespace Halak
{
    UIImage* UISprite::GetImage() const
    {
        return image;
    }

    bool UISprite::GetAutoResize() const
    {
        return autoResize;
    }

    void UISprite::SetAutoResize(bool value)
    {
        autoResize = value;
    }

    bool UISprite::GetHorizontalFlip() const
    {
        return horizontalFlip;
    }

    void UISprite::SetHorizontalFlip(bool value)
    {
        horizontalFlip = value;
    }

    bool UISprite::GetVerticalFlip() const
    {
        return verticalFlip;
    }

    void UISprite::SetVerticalFlip(bool value)
    {
        verticalFlip = value;
    }
}
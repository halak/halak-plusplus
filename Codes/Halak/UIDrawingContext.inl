namespace Halak
{
    void UIDrawingContext::Draw(UIVisual* target)
    {
        Visit(target);
    }

    void UIDrawingContext::Draw(UIImage* image)
    {
        Draw(GetCurrentBounds(), GetCurrentClippedBounds(), image, false, false);
    }

    void UIDrawingContext::Draw(UIImage* image, bool horizontalFlip, bool verticalFlip)
    {
        Draw(GetCurrentBounds(), GetCurrentClippedBounds(), image, horizontalFlip, verticalFlip);
    }

    void UIDrawingContext::DrawString(Font* font, const String& text)
    {
        DrawString(GetCurrentBounds(), GetCurrentClippedBounds(), font, text);
    }

    void UIDrawingContext::DrawString(const FontString& fontString)
    {
        DrawString(GetCurrentBounds(), GetCurrentClippedBounds(), fontString);
    }
}
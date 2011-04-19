namespace Halak
{
    void UIDrawingContext::Draw(UIVisual* target)
    {
        Visit(target);
    }
}
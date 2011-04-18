namespace Halak
{
    float UIVisual::GetOpacity() const
    {
        return opacity;
    }

    bool UIVisual::GetShown() const
    {
        return shown;
    }

    UIFrame* UIVisual::GetFrame() const
    {
        return frame;
    }

    UIWindow* UIVisual::GetParent() const
    {
        return parent;
    }
    
    bool UIVisual::IsVisible() const
    {
        return GetShown() && GetOpacity() > 0.0f;
    }
}
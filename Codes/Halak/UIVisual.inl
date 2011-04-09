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

    const UIFramePtr& UIVisual::GetFrame() const
    {
        return frame;
    }

    const UIWindowWeakPtr& UIVisual::GetParent() const
    {
        return parent;
    }
    
    bool UIVisual::IsVisible() const
    {
        return GetShown() && GetOpacity() > 0.0f;
    }
}
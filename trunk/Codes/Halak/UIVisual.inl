namespace Halak
{
    void UIVisual::Show()
    {
        SetShown(true);
    }

    void UIVisual::Hide()
    {
        SetShown(false);
    }

    float UIVisual::GetOpacity() const
    {
        return opacity;
    }

    bool UIVisual::GetShown() const
    {
        return shown;
    }

    void UIVisual::SetShown(bool value)
    {
        shown = value;
    }

    UIFrame* UIVisual::GetFrame() const
    {
        return frame;
    }

    UIEventMap* UIVisual::GetEventMap() const
    {
        return eventMap;
    }

    UIPanel* UIVisual::GetParent() const
    {
        return parent;
    }
    
    bool UIVisual::IsVisible() const
    {
        return GetShown() && GetOpacity() > 0.0f;
    }
}
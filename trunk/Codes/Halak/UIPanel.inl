namespace Halak
{
    Vector2 UIPanel::GetDesiredSize() const
    {
        return desiredSize;
    }

    const UIPanel::VisualCollection& UIPanel::GetChildren() const
    {
        return children;
    }
}
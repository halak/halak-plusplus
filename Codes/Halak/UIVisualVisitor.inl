namespace Halak
{
    bool UIVisualVisitor::GetVisibleOnly() const
    {
        return visibleOnly;
    }

    void UIVisualVisitor::SetVisibleOnly(bool value)
    {
        visibleOnly = value;
    }

    UIVisual* UIVisualVisitor::GetCurrentVisual() const
    {
        return currentVisual;
    }

    float UIVisualVisitor::GetCurrentOpacity() const
    {
        return currentOpacity;
    }

    const RectangleF& UIVisualVisitor::GetCurrentBounds() const
    {
        return currentBounds;
    }

    const RectangleF& UIVisualVisitor::GetCurrentClippedBounds() const
    {
        return currentClippedBounds;
    }

    const Matrix4& UIVisualVisitor::GetCurrentTransform() const
    {
        return currentTransform;
    }
}
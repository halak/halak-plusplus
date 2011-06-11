namespace Halak
{
    float UIVisualVisitor::GetFieldOfView() const
    {
        return fieldOfView;
    }

    bool UIVisualVisitor::GetVisibleOnly() const
    {
        return visibleOnly;
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
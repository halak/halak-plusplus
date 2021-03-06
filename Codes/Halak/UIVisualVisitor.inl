namespace Halak
{
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

    const Matrix4& UIVisualVisitor::GetViewTransform() const
    {
        return viewTransform;
    }

    const Matrix4& UIVisualVisitor::GetProjectionTransform() const
    {
        return projectionTransform;
    }
}
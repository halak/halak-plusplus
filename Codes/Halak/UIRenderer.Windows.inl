namespace Halak
{
    GraphicsDevice* UIRenderer::GetGraphicsDevice() const
    {
        return graphicsDevice;
    }

    float UIRenderer::GetFieldOfView() const
    {
        return fieldOfView;
    }

    const Matrix4& UIRenderer::GetViewTransform()
    {
        UpdateViewProjectionTransform();
        return viewTransform;
    }

    const Matrix4& UIRenderer::GetProjectionTransform()
    {
        UpdateViewProjectionTransform();
        return projectionTransform;
    }

    const Matrix4& UIRenderer::GetInversedViewTransform()
    {
        UpdateViewProjectionTransform();
        return viewTransformInv;
    }

    const Matrix4& UIRenderer::GetInversedProjectionTransform()
    {
        UpdateViewProjectionTransform();
        return projectionTransformInv;
    }
}
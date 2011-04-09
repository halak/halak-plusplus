namespace Halak
{
    SpriteRenderer* UIRenderer::GetSpriteRenderer() const
    {
        return spriteRenderer;
    }

    void UIRenderer::SetSpriteRenderer(SpriteRenderer* value)
    {
        spriteRenderer = value;
    }
}
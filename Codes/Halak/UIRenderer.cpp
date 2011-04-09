#include <Halak/PCH.h>
#include <Halak/UIRenderer.h>

namespace Halak
{
    UIRenderer::UIRenderer()
    {
    }

    UIRenderer::UIRenderer(SpriteRenderer* spriteRenderer)
        : spriteRenderer(spriteRenderer)
    {
    }
}
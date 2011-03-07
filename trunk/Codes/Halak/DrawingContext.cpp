#include <Halak/DrawingContext.h>

namespace Halak
{
    DrawingContext::DrawingContext(SpriteRenderer* spriteRenderer)
        : spriteRenderer(spriteRenderer)
    {
    }

    DrawingContext::~DrawingContext()
    {
    }
}
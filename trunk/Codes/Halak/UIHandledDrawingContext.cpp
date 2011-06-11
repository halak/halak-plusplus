#include <Halak/UIHandledDrawingContext.h>

namespace Halak
{
    UIHandledDrawingContext::UIHandledDrawingContext(SpriteRenderer* renderer)
        : UIDrawingContext(renderer),
          handler(nullptr)
    {
    }

    UIHandledDrawingContext::UIHandledDrawingContext(SpriteRenderer* renderer, IHandler* handler)
        : UIDrawingContext(renderer),
          handler(handler)
    {
    }

    UIHandledDrawingContext::~UIHandledDrawingContext()
    {
    }
}
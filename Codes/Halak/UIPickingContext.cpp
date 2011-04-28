#include <Halak/PCH.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    UIPickingContext::UIPickingContext(Vector2 point)
        : point(point),
          result(nullptr)
    {
    }

    UIPickingContext::~UIPickingContext()
    {
    }

    bool UIPickingContext::Pick(UIVisual* target)
    {
        Visit(target);
        return GetResult() != nullptr;
    }

    void UIPickingContext::SetResult(UIVisual* value)
    {
        result = value;
    }

    void UIPickingContext::OnVisit(UIVisual* target)
    {
        target->OnPick(*this);
    }
}
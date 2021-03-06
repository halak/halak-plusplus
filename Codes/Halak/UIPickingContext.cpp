#include <Halak/PCH.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIRenderer.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    UIPickingContext::UIPickingContext(UIRenderer* renderer, Vector2 point)
        : UIVisualVisitor(renderer->GetViewTransform(), renderer->GetInversedViewTransform(), renderer->GetProjectionTransform(), true),
          point(point),
          currentPoint(point),
          result(nullptr)
    {
    }

    UIPickingContext::UIPickingContext(UIRenderer* renderer, Vector2 point, bool visibleOnly)
        : UIVisualVisitor(renderer->GetViewTransform(), renderer->GetInversedViewTransform(), renderer->GetProjectionTransform(), visibleOnly),
          point(point),
          currentPoint(point),
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

    void UIPickingContext::OnVisit()
    {
        const Vector2 oldPoint = currentPoint;

        currentPoint = Unproject(point);

        GetCurrentVisual()->OnPick(*this);

        currentPoint = oldPoint;
    }
}
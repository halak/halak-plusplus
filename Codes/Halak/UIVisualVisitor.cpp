#include <Halak/PCH.h>
#include <Halak/UIVisualVisitor.h>
#include <Halak/Assert.h>
#include <Halak/UIFrame.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    static const float BigFloat = 10000.0f;
    static const RectangleF BigRectangle = RectangleF(-BigFloat, -BigFloat, BigFloat + BigFloat, BigFloat + BigFloat);

    UIVisualVisitor::UIVisualVisitor()
        : visibleOnly(true),
          currentOpacity(1.0f),
          currentBounds(BigRectangle),
          currentClippedBounds(BigRectangle),
          currentTransform(Matrix4::Identity)
    {
    }

    UIVisualVisitor::~UIVisualVisitor()
    {
    }

    void UIVisualVisitor::Visit(UIVisual* target)
    {
        HKAssert(target != nullptr);

        if (visibleOnly && target->IsVisible() == false)
            return;
        if (target->GetFrame() == nullptr) // visible only가 아니더라도 Frame이 없으면 작업을 수행하지 않는다.
            return;

        const UIVisualPtr oldVisual = currentVisual;
        const float oldOpacity = currentOpacity;
        const RectangleF oldBounds = currentBounds;
        const RectangleF oldClippedBounds = currentClippedBounds;
        const Matrix4 oldTransform = currentTransform;

        const RectangleF bounds = target->GetFrame()->ComputeBounds(*this);

        currentVisual = target;
        currentOpacity *= target->GetOpacity();
        currentBounds = bounds;
        currentClippedBounds = RectangleF::Intersect(currentClippedBounds, currentBounds);
        currentTransform = Matrix4::Identity;

        OnVisit(target);

        currentVisual = oldVisual;
        currentOpacity = oldOpacity;
        currentBounds = oldBounds;
        currentClippedBounds = oldClippedBounds;
        currentTransform = oldTransform;
    }
}
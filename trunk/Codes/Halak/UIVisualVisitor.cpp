#include <Halak/PCH.h>
#include <Halak/UIVisualVisitor.h>
#include <Halak/Assert.h>
#include <Halak/Math.h>
#include <Halak/UIFrame.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    static const float BigFloat = 10000.0f;
    static const RectangleF BigRectangle = RectangleF(-BigFloat, -BigFloat, BigFloat + BigFloat, BigFloat + BigFloat);

    UIVisualVisitor::UIVisualVisitor()
        : fieldOfView(Math::PiOver2),
          visibleOnly(true),
          currentOpacity(1.0f),
          currentBounds(BigRectangle),
          currentClippedBounds(BigRectangle),
          currentTransform(Matrix4::Identity),
          currentTransformInv(Matrix4::Identity),
          parentTransform(Matrix4::Identity),
          parentTransformInv(Matrix4::Identity)
    {
    }

    UIVisualVisitor::UIVisualVisitor(float fieldOfView, bool visibleOnly)
        : fieldOfView(Math::Clamp(fieldOfView, 0.0f, Math::Pi)),
          visibleOnly(visibleOnly),
          currentOpacity(1.0f),
          currentBounds(BigRectangle),
          currentClippedBounds(BigRectangle),
          currentTransform(Matrix4::Identity),
          currentTransformInv(Matrix4::Identity),
          parentTransform(Matrix4::Identity),
          parentTransformInv(Matrix4::Identity)
    {
    }

    UIVisualVisitor::~UIVisualVisitor()
    {
    }

    Vector2 UIVisualVisitor::Project(Vector2 point) const
    {
        return point;
    }

    Vector2 UIVisualVisitor::Unproject(Vector2 point) const
    {
        return point;
    }

    Vector2 UIVisualVisitor::UnprojectByParent(Vector2 point) const
    {
        return point;
    }

    void UIVisualVisitor::Project(Vector2* inOutPoints, int count) const
    {
        if (inOutPoints == nullptr || count == 0)
            return;
    }

    void UIVisualVisitor::Visit(UIVisual* target)
    {
        HKAssert(target != nullptr);

        if (visibleOnly && target->IsVisible() == false)
            return;
        if (target->GetFrame() == nullptr) // visible only가 아니더라도 Frame이 없으면 작업을 수행하지 않는다.
            return;

        UIVisual*const oldVisual = currentVisual;
        const float oldOpacity = currentOpacity;
        const RectangleF oldBounds = currentBounds;
        const RectangleF oldClippedBounds = currentClippedBounds;
        const Matrix4 oldTransform = currentTransform;
        const Matrix4 oldTransformInv = currentTransformInv;
        const Matrix4 oldParentTransform = parentTransform;
        const Matrix4 oldParentTransformInv = parentTransformInv;

        const RectangleF bounds = target->ComputeBounds(*this);

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
        currentTransformInv = oldTransformInv;
        parentTransform = oldParentTransform;
        parentTransformInv = oldParentTransformInv;
    }
}
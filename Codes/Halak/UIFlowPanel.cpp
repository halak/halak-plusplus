#include <Halak/PCH.h>
#include <Halak/UIFlowPanel.h>

namespace Halak
{
    UIFlowPanel::UIFlowPanel()
        : direction(LeftToRight)
    {
    }

    UIFlowPanel::~UIFlowPanel()
    {
    }

    void UIFlowPanel::SetDirection(Direction value)
    {
        direction = value;
    }

    void UIFlowPanel::OnDraw(UIDrawingContext& context)
    {
    }

    void UIFlowPanel::OnPick(UIPickingContext& context)
    {
    }

    void UIFlowPanel::OnChildAdded(UIVisual* child)
    {
    }

    void UIFlowPanel::OnChildRemoved(UIVisual* child)
    {
    }

    void UIFlowPanel::OnChildrenAdded(const VisualCollection& children)
    {
    }

    void UIFlowPanel::OnChildrenRemoved(const VisualCollection& children)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIFlowPanel::ArrangedFrame::ArrangedFrame()
    {
    }

    UIFlowPanel::ArrangedFrame::~ArrangedFrame()
    {
    }

    RectangleF UIFlowPanel::ArrangedFrame::ComputeBounds(UIVisualVisitor& context)
    {
        return Rectangle::Empty;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIFlowPanel::ArrangedFrame::PickingContext::PickingContext()
    {
    }

    UIFlowPanel::ArrangedFrame::PickingContext::~PickingContext()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIFlowPanel::ArrangedFrame::DrawingContext::DrawingContext()
    {
    }

    UIFlowPanel::ArrangedFrame::DrawingContext::~DrawingContext()
    {
    }
}
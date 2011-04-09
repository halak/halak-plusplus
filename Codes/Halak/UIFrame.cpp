#include <Halak/PCH.h>
#include <Halak/UIFrame.h>
#include <Halak/Exception.h>

namespace Halak
{
    UIFrame::UIFrame()
    {
    }

    UIFrame::~UIFrame()
    {
    }

    void UIFrame::Move(Vector2 /*displacement*/)
    {
        HKThrow(NotSupportedException());
    }

    bool UIFrame::IsMovable() const
    {
        return false;
    }

    void UIFrame::Resize(float /*left*/, float /*top*/, float /*right*/, float /*bottom*/)
    {
        HKThrow(NotSupportedException());
    }

    void UIFrame::ResizeTo(Vector2 /*size*/)
    {
        HKThrow(NotSupportedException());
    }

    bool UIFrame::IsResizable() const
    {
        return false;
    }
}
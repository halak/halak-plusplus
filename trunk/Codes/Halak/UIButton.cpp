#include <Halak/PCH.h>
#include <Halak/UIButton.h>

namespace Halak
{
    UIButton::UIButton()
    {
    }

    UIButton::~UIButton()
    {
    }

    bool UIButton::OnMouseEnter(const UIMouseEventArgs& args)
    {
        return false;
    }

    bool UIButton::OnMouseLeave(const UIMouseEventArgs& args)
    {
        return false;
    }

    bool UIButton::OnMouseLeftDown(const UIMouseEventArgs& args)
    {
        return false;
    }

    bool UIButton::OnMouseLeftUp(const UIMouseEventArgs& args)
    {
        return false;
    }
}
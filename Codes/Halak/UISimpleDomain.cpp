#include <Halak/PCH.h>
#include <Halak/UISimpleDomain.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UISimpleDomain::UISimpleDomain()
    {
    }

    UISimpleDomain::UISimpleDomain(UIWindow* root)
        : UIDomain(root)
    {
    }

    UISimpleDomain::UISimpleDomain(UIWindow* root, UIWindow* focus)
        : UIDomain(root),
          focus(focus)
    {
    }

    UISimpleDomain::~UISimpleDomain()
    {
    }

    UIWindow* UISimpleDomain::GetFocus() const
    {
        return focus;
    }

    void UISimpleDomain::SetFocus(UIWindow* value)
    {
        focus = value;
    }
}
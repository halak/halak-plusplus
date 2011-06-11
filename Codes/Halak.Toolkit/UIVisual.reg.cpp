#include <Halak.Toolkit/PCH.h>
#include <Halak/UIVisual.h>
#include <Halak/UIFrame.h>
#include <Halak/UIWindow.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/RegistrationContexts.h>
using namespace Halak::Toolkit;

namespace Halak
{
    void UIVisual::__Startup__()
    {
        Class<UIVisual>()
            .SetID(HKMakeFOURCC('U', 'I', 'V', 'S'), "Halak::UI", "UIVisual")
            .Inherits<UIElement>()
            .Add(new PropertyInfo(HKMakeFOURCC('O', 'P', 'A', 'C'), "Opacity", &UIVisual::GetOpacity, &UIVisual::SetOpacity)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S', 'H', 'O', 'W'), "Shown", &UIVisual::GetShown, &UIVisual::SetShown)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('F', 'R', 'M', 'E'), "Frame", &UIVisual::GetFrame, &UIVisual::SetFrame)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('P', 'A', 'R', 'N'), "Parent", &UIVisual::GetParent)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('V', 'I', 'S', 'B'), "IsVisible", &UIVisual::IsVisible)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('P', 'A', 'N', 'L'), "IsPanel", &UIVisual::IsPanel)).Close()
            .Close();
    }
}
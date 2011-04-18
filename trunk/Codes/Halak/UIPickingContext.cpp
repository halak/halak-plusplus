#include <Halak/PCH.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIVisual.h>

namespace Halak
{
    UIPickingContext::UIPickingContext()
    {
    }
    
    UIPickingContext::~UIPickingContext()
    {
    }

    void UIPickingContext::OnVisit(UIVisual* target)
    {
        target->OnPick(*this);
    }
}
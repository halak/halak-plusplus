#include <Halak/PCH.h>
#include <Halak/UIFixedTargetWindow.h>

namespace Halak
{
    UIFixedTargetWindow::UIFixedTargetWindow()
        : target(nullptr)
    {
    }
    
    UIFixedTargetWindow::UIFixedTargetWindow(UIWindow* target)
        : target(target)
    {
    }

    UIFixedTargetWindow::~UIFixedTargetWindow()
    {
    }

    UIWindow* UIFixedTargetWindow::GetTarget() const
    {
        return target;
    }

    void UIFixedTargetWindow::SetTarget(UIWindow* value)
    {
        target = value;
    }

    void* UIFixedTargetWindow::QueryInterface(uint classID)
    {
        if (classID == ITargetWindow::ClassID)
            return static_cast<ITargetWindow*>(this);
        else
            return GameComponent::QueryInterface(classID);
    }
}
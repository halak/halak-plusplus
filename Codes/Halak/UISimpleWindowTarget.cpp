#include <Halak/PCH.h>
#include <Halak/UISimpleWindowTarget.h>

namespace Halak
{
    UISimpleWindowTarget::UISimpleWindowTarget()
        : target(nullptr)
    {
    }
    
    UISimpleWindowTarget::UISimpleWindowTarget(UIWindow* target)
        : target(target)
    {
    }

    UISimpleWindowTarget::~UISimpleWindowTarget()
    {
    }

    UIWindow* UISimpleWindowTarget::GetTarget() const
    {
        return target;
    }

    void UISimpleWindowTarget::SetTarget(UIWindow* value)
    {
        target = value;
    }

    void* UISimpleWindowTarget::QueryInterface(uint classID)
    {
        if (classID == IWindowTarget::ClassID)
            return static_cast<IWindowTarget*>(this);
        else
            return GameComponent::QueryInterface(classID);
    }
}
namespace Halak
{
    UIButton::State UIButton::GetCurrentState() const
    {
        return currentState;
    }

    UIWindow* UIButton::GetCurrentWindow() const
    {
        switch (currentState)
        {
            case NormalState:
                return normalWindow;
            case PushedState:
                return pushedWindow;
            case HoveringState:
                return hoveringWindow;
            default:
                return nullptr;
        }
    }

    UIWindow* UIButton::GetNormalWindow() const
    {
        return normalWindow;
    }

    UIWindow* UIButton::GetPushedWindow() const
    {
        return pushedWindow;
    }

    UIWindow* UIButton::GetHoveringWindow() const
    {
        return hoveringWindow;
    }

    bool UIButton::GetHideInactives() const
    {
        return hideInactives;
    }
}
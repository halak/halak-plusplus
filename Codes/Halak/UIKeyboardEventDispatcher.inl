namespace Halak
{
    ITargetWindow* UIKeyboardEventDispatcher::GetTargetWindow() const
    {
        return targetWindow;
    }

    Keyboard* UIKeyboardEventDispatcher::GetDevice() const
    {
        return device;
    }
}
namespace Halak
{
    IWindowTarget* UIKeyboardEventDispatcher::GetWindowTarget() const
    {
        return windowTarget;
    }

    Keyboard* UIKeyboardEventDispatcher::GetDevice() const
    {
        return device;
    }
}
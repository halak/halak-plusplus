namespace Halak
{
    IWindowTarget* UIMouseEventDispatcher::GetWindowTarget() const
    {
        return windowTarget;
    }

    Mouse* UIMouseEventDispatcher::GetDevice() const
    {
        return device;
    }
}
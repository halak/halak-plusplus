namespace Halak
{
    UIDomain* UIKeyboardEventDispatcher::GetDomain() const
    {
        return domain;
    }

    Keyboard* UIKeyboardEventDispatcher::GetDevice() const
    {
        return device;
    }
}
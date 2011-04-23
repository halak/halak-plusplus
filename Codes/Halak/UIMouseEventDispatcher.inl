namespace Halak
{
    UIDomain* UIMouseEventDispatcher::GetDomain() const
    {
        return domain;
    }

    Mouse* UIMouseEventDispatcher::GetDevice() const
    {
        return device;
    }
}
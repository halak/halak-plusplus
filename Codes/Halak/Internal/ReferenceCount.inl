namespace Halak
{
    ReferenceCount::ReferenceCount()
        : strong(0),
          weak(0)
    {
    }

    bool ReferenceCount::IsAlive() const
    {
        return strong != 0;
    }
}
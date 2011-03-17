namespace Halak
{
    ReferenceCount::ReferenceCount()
        : strong(0),
          weak(0)
    {
    }

    ReferenceCount::ReferenceCount(const ReferenceCount& original)
        : strong(original.strong),
          weak(original.weak)
    {
    }

    int ReferenceCount::GetStrong() const
    {
        return static_cast<int>(strong);
    }

    int ReferenceCount::GetWeak() const
    {
        return static_cast<int>(weak);
    }

    bool ReferenceCount::IsAlive() const
    {
        return strong != 0;
    }

    ReferenceCount& ReferenceCount::operator = (const ReferenceCount& right)
    {
        strong = right.strong;
        weak = right.weak;
        return *this;
    }
}
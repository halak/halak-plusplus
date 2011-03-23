namespace Halak
{
    template <typename T> SharedPointer<T> SharedObject::CastTo()
    {
        return SharedPointer<T>(static_cast<T*>(this));
    }
}
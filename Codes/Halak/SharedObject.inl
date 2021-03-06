namespace Halak
{
    template <typename To> SharedPointer<To> SharedObject::This()
    {
        return SharedPointer<To>(static_cast<To*>(this), life);
    }

    template <typename To, typename ThisType> SharedPointer<To> SharedObject::This(ThisType* thisInstance)
    {
        return SharedPointer<To>(static_cast<To*>(thisInstance), life);
    }
}
namespace Halak
{
    template <typename T> SharedPointer<T> SharedObject::CastTo()
    {
        return SharedPointer<T>(static_cast<T*>(this), referenceCount);
    }

#   if (defined(HALAK_RTTI))
        template <typename T> SharedPointer<T> SharedObject::DynamicCastTo()
        {
            return SharedPointer<T>(dynamic_cast<T*>(this), referenceCount);
        }
#   endif
}
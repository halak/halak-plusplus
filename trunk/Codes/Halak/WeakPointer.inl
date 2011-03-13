namespace Halak
{
    template <typename T> WeakPointer<T>::WeakPointer()
        : pointee(0),
          referenceCount(0)
    {
    }

    template <typename T> WeakPointer<T>::WeakPointer(const SharedPointer<T>& pointer)
        : pointee(pointer),
          referenceCount(pointee ? pointee->referenceCount : nullptr)
    {
        if (referenceCount)
            referenceCount->IncreaseWeakCount();
    }

    template <typename T> WeakPointer<T>::WeakPointer(const WeakPointer<T>& original)
        : pointee(original.pointee),
          referenceCount(original.referenceCount)
    {
        if (referenceCount)
            referenceCount->IncreaseWeakCount();
    }

    template <typename T> WeakPointer<T>::~WeakPointer()
    {
        if (referenceCount)
            referenceCount->DecreaseWeakCount();
    }

    template <typename T> SharedPointer<T> WeakPointer<T>::Lock() const
    {
        if (referenceCount && referenceCount->IsAlive())
            return SharedPointer<T>(pointee);
        else
            return nullptr;
    }

    template <typename T> bool WeakPointer<T>::IsAlive() const
    {
        return referenceCount && referenceCount->IsAlive();
    }

    template <typename T> WeakPointer<T>& WeakPointer<T>::operator = (const WeakPointer<T>& right) const
    {
        if (referenceCount)
            referenceCount->DecreaseWeakCount();

        pointee = right.pointee;
        referenceCount = right.referenceCount;

        if (referenceCount)
            referenceCount->IncreaseWeakCount();

        return *this;
    }

    template <typename T> WeakPointer<T>& WeakPointer<T>::operator = (const SharedPointer<T>& right) const
    {
        return *this;
    }

    template <typename T> bool WeakPointer<T>::operator == (const WeakPointer<T>& right) const
    {
        if (IsAlive() == right.IsAlive())
            return pointee == right.pointee;
        else
            return false;
    }

    template <typename T> bool WeakPointer<T>::operator == (const SharedPointer<T>& right) const
    {
        if (IsAlive() != static_cast<bool>(right.GetPointee() != nullptr))
            return pointee == right.GetPointee();
        else
            return false;
    }

    template <typename T> bool WeakPointer<T>::operator == (T* right) const
    {
        if (IsAlive() != static_cast<bool>(right != nullptr))
            return pointee == right;
        else
            return false;
    }

    template <typename T> bool WeakPointer<T>::operator != (const WeakPointer<T>& right) const
    {
        return !operator == (right);
    }

    template <typename T> bool WeakPointer<T>::operator != (const SharedPointer<T>& right) const
    {
        return !operator == (right);
    }

    template <typename T> bool WeakPointer<T>::operator != (T* right) const
    {
        return !operator == (right);
    }

    template <typename T> WeakPointer<T>::operator T* () const
    {
        if (IsAlive())
            return pointee;
        else
            return nullptr;
    }

    template <typename T> WeakPointer<T>::operator SharedPointer<T> () const
    {
        return Lock();
    }
}
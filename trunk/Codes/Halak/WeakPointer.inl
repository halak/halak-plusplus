namespace Halak
{
    template <typename T> WeakPointer<T>::WeakPointer()
        : pointee(0),
          referenceCount(0)
    {
    }

    template <typename T> WeakPointer<T>::WeakPointer(const SharedPointer<T>& pointer)
        : pointee(pointer),
          referenceCount(pointee ? pointee.referenceCount : 0)
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
            return 0;
    }

    template <typename T> bool WeakPointer<T>::IsAlive() const
    {
        return referenceCount && referenceCount->IsAlive();
    }

    template <typename T> WeakPointer<T>& WeakPointer<T>::operator = (const WeakPointer<T>& right)
    {
        if (referenceCount)
            referenceCount->DecreaseWeakCount();

        pointee = right.pointee;
        referenceCount = right.referenceCount;

        if (referenceCount)
            referenceCount->IncreaseWeakCount();

        return *this;
    }

    template <typename T> WeakPointer<T>& WeakPointer<T>::operator = (const SharedPointer<T>& right)
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
        if (IsAlive() != static_cast<bool>(right.GetPointee() != 0))
            return pointee == right.GetPointee();
        else
            return false;
    }

    template <typename T> bool WeakPointer<T>::operator == (T* right) const
    {
        if (IsAlive() != static_cast<bool>(right != 0))
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
            return 0;
    }

    template <typename T> WeakPointer<T>::operator SharedPointer<T> () const
    {
        return Lock();
    }
}
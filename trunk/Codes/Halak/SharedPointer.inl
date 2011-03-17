namespace Halak
{
    template <typename T> SharedPointer<T>::SharedPointer()
        : pointee(0),
          referenceCount(0)
    {
    }

    template <typename T> SharedPointer<T>::SharedPointer(T* pointee)
        : pointee(pointee),
          referenceCount(AcquireReferenceCount(pointee))
    {
        if (referenceCount)
            referenceCount->IncreaseStrongCount();
    }

    template <typename T> SharedPointer<T>::SharedPointer(const SharedPointer<T>& original)
        : pointee(original.pointee),
          referenceCount(original.referenceCount)
    {
        if (referenceCount)
            referenceCount->IncreaseStrongCount();
    }

    template <typename T> SharedPointer<T>::~SharedPointer()
    {
        if (referenceCount && referenceCount->DecreaseStrongCount())
            delete pointee;
    }

    template <typename T> void SharedPointer<T>::Reset(const SharedPointer<T>& right)
    {
        if (this == &right)
            return;

        if (referenceCount && referenceCount->DecreaseStrongCount())
            delete referenceCount;

        pointee = right.pointee;
        referenceCount = right.referenceCount;

        if (referenceCount)
            referenceCount->IncreaseStrongCount();
    }

    template <typename T> void SharedPointer<T>::Reset(T* right)
    {
        if (pointee != right)
        {
            if (referenceCount && referenceCount->DecreaseStrongCount())
                delete pointee;

            pointee = right;
            referenceCount = AcquireReferenceCount(right);

            if (referenceCount)
                referenceCount->IncreaseStrongCount();
        }
    }

    template <typename T> T* SharedPointer<T>::GetPointee() const
    {
        return pointee;
    }

    template <typename T> int SharedPointer<T>::GetReferenceCount() const
    {
        if (referenceCount)
            return referenceCount->GetStrong();
        else
            return 0;
    }

    template <typename T> int SharedPointer<T>::GetWeakReferenceCount() const
    {
        if (referenceCount)
            return referenceCount->GetWeak();
        else
            return 0;
    }

    template <typename T> SharedPointer<T>& SharedPointer<T>::operator = (const SharedPointer<T>& right)
    {
        Reset(right);
        return *this;
    }

    template <typename T> SharedPointer<T>& SharedPointer<T>::operator = (T* right)
    {
        Reset(right);
        return *this;
    }

    template <typename T> bool SharedPointer<T>::operator == (const SharedPointer<T>& right) const
    {
        return pointee == right.pointee;
    }

    template <typename T> bool SharedPointer<T>::operator == (T* right) const
    {
        return pointee == right;
    }

    template <typename T> bool SharedPointer<T>::operator != (const SharedPointer<T>& right) const
    {
        return !operator == (right);
    }

    template <typename T> bool SharedPointer<T>::operator != (T* right) const
    {
        return !operator == (right);
    }

    template <typename T> SharedPointer<T>::operator T* () const
    {
        return pointee;
    }

    template <typename T> T& SharedPointer<T>::operator * () const
    {
        return *pointee;
    }

    template <typename T> T* SharedPointer<T>::operator -> () const
    {
        return pointee;
    }

    template <typename T> ReferenceCount* SharedPointer<T>::AcquireReferenceCount(SharedObject* instance)
    {
        return instance ? instance->referenceCount : 0;
    }
}
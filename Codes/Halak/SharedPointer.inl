#include <Halak/SharedObject.h>
#include <Halak/Internal/ReferenceCount.h>

namespace Halak
{
    template <typename T> SharedPointer<T>::SharedPointer()
        : pointee(0)
    {
    }

    template <typename T> SharedPointer<T>::SharedPointer(T* pointee)
        : pointee(pointee)
    {
        if (pointee)
            pointee->referenceCount->IncreaseStrongCount();
    }

    template <typename T> SharedPointer<T>::SharedPointer(const SharedPointer<T>& original)
        : pointee(original.pointee)
    {
        if (pointee)
            pointee->referenceCount->IncreaseStrongCount();
    }

    template <typename T> SharedPointer<T>::~SharedPointer()
    {
        if (pointee && pointee->referenceCount->DecreaseStrongCount())
            delete pointee;
    }

    template <typename T> T* SharedPointer<T>::GetPointee() const
    {
        return pointee;
    }

    template <typename T> SharedPointer<T>& SharedPointer<T>::operator = (const SharedPointer<T>& right) const
    {
        return operator = (right.pointee);
    }

    template <typename T> SharedPointer<T>& SharedPointer<T>::operator = (T* right) const
    {
        if (pointee != right)
        {
            if (pointee && pointee->referenceCount->DecreaseStrongCount())
                delete pointee;

            pointee = right.pointee;

            if (pointee)
                pointee->referenceCount->IncreaseStrongCount();
        }

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
}
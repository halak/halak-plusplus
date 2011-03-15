namespace Halak
{
#   if (defined(HALAK_RTTI))
        template <typename T> bool DynamicDispose(T* instance)
        {
            if (IDisposable* disposable = dynamic_cast<IDisposable*>(instance))
            {
                disposable->Dispose();
                return true;
            }
            else
                return false;
        }

        template <typename T> bool DynamicDispose(SharedPointer<T> instance)
        {
            return DynamicDispose<T>(instance.GetPointee());
        }
#   endif
}
namespace Halak
{
    template <typename T, uint32 ClassID> void StructOperator<T, ClassID>::Destruct(void* object)
    {
        delete static_cast<T*>(object);
    }
}
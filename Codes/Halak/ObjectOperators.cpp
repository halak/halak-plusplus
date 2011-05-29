#include <Halak/ObjectOperators.h>

namespace Halak
{
    Any ObjectOperator::Command(void* /*object*/, const String& /*name*/, const Any& /*arg1*/, const Any& /*arg2*/, const Any& /*arg3*/, const Any& /*arg4*/)
    {
        return Any::Missing;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void GameComponentOperator::Destruct(void* object)
    {
        delete static_cast<GameComponent*>(object);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void SharedObjectOperator::Destruct(void* /*object*/)
    {
    }
}
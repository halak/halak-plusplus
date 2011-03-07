#include <Halak/ICloneable.h>
#include <Halak/CloningContext.h>

namespace Halak
{
    ICloneable::ICloneable()
    {
    }

    ICloneable::ICloneable(CloningContext& /*context*/)
    {
    }

    ICloneable* ICloneable::Clone() const
    {
        CloningContext context;
        return CloneWith(context);
    }
}
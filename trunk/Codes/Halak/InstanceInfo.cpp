#include <Halak/PCH.h>
#include <Halak/InstanceInfo.h>
#include <Halak/Assert.h>

namespace Halak
{
    const InstanceInfo InstanceInfo::Empty = InstanceInfo(nullptr);

    byte InstanceInfo::ComposeFields(int pointerDepth, bool isReference)
    {
        HKAssertDebug(0 <= pointerDepth && pointerDepth <= PointerDepthBits);

        byte result = 0x00;
        if (pointerDepth > 0)
            result |= static_cast<byte>(pointerDepth);
        if (isReference)
            result |= IsReferenceBit;

        return result;
    }
};
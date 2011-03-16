#include <Halak/PCH.h>
#include <Halak/Quaternion.h>

namespace Halak
{  
    const Quaternion Quaternion::Zero     = Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    const Quaternion Quaternion::Identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}
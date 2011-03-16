#include <Halak/PCH.h>
#include <Halak/Startup.h>
#include <Halak/All.h>

namespace Halak
{
#   define HKNothing1(_)
#   define HKNothing2(_, _)
#   define HKRegisterClassID(classname)

    void Startup()
    {
        HKClasses(HKNothing, HKRegisterClassID, HKRegisterClassID, HKRegisterClassID, HKNothing2, HKNothing2);
    }
}
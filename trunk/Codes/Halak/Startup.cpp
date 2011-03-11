#include <Halak/Startup.h>
#include <Halak/All.h>

namespace Halak
{
#   define HKNothing(_)
#   define HKRegisterClassID(classname)

    void Startup()
    {
        HKClasses(HKNothing, HKRegisterClassID, HKRegisterClassID, HKRegisterClassID);
    }
}
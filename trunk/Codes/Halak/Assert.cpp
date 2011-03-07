#include <Halak/Assert.h>

namespace Halak
{
    void Assert(const char* /*expression*/, const char* /*filename*/, int /*line*/)
    {
        __asm int 3
    }
}
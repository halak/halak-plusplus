#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/JSONStreamReader.h>
#include <Halak/Stream.h>

namespace Halak
{
    namespace Toolkit
    {
        JSONStreamReader::JSONStreamReader(StreamPtr source)
            : StreamReader(source)
        {
        }

        JSONStreamReader::~JSONStreamReader()
        {
        }
    }
}
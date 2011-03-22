#include <Halak/JSONStreamReader.h>

namespace Halak
{
    JSONStreamReader::JSONStreamReader(StreamPtr source)
        : StreamReader(source)
    {
    }

    JSONStreamReader::~JSONStreamReader()
    {
    }
}
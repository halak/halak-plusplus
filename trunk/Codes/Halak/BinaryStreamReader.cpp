#include <Halak/PCH.h>
#include <Halak/BinaryStreamReader.h>
#include <Halak/Stream.h>

namespace Halak
{
    BinaryStreamReader::BinaryStreamReader(StreamPtr source)
        : StreamReader(source)
    {
    }

    BinaryStreamReader::~BinaryStreamReader()
    {
    }
}
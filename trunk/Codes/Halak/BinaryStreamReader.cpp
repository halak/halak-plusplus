#include <Halak/BinaryStreamReader.h>

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
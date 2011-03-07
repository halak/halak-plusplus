#include <Halak/BinaryStreamWriter.h>

namespace Halak
{
    BinaryStreamWriter::BinaryStreamWriter(StreamPtr destination)
        : StreamWriter(destination)
    {
    }

    BinaryStreamWriter::~BinaryStreamWriter()
    {
    }
}
#include <Halak/PCH.h>
#include <Halak/BinaryStreamWriter.h>
#include <Halak/Stream.h>

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
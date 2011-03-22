#include <Halak/JSONStreamWriter.h>

namespace Halak
{
    JSONStreamWriter::JSONStreamWriter(StreamPtr destination)
        : StreamWriter(destination)
    {
    }

    JSONStreamWriter::~JSONStreamWriter()
    {
    }
}
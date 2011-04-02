#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/JSONStreamWriter.h>
#include <Halak/Stream.h>

namespace Halak
{
    namespace Toolkit
    {
        JSONStreamWriter::JSONStreamWriter(StreamPtr destination)
            : StreamWriter(destination)
        {
        }

        JSONStreamWriter::~JSONStreamWriter()
        {
        }
    }
}
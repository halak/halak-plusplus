#include <Halak/PCH.h>
#include <Halak/StreamWriter.h>
#include <Halak/Assert.h>
#include <Halak/Stream.h>
#include <Halak/String.h>

namespace Halak
{
    StreamWriter::StreamWriter(StreamPtr destination)
        : destination(destination)
    {
    }

    StreamWriter::~StreamWriter()
    {
    }

    template <typename T> void StreamWriter::WriteTemplate(T value)
    {
        const int writtenSize = destination->Write(&value, sizeof(value));
        HKAssert(writtenSize == sizeof(value));
    }

    void StreamWriter::Write(bool value)
    {
        WriteTemplate<bool>(value);
    }

    void StreamWriter::Write(char value)
    {
        WriteTemplate<char>(value);
    }

    void StreamWriter::Write(uchar value)
    {
        WriteTemplate<uchar>(value);
    }

    void StreamWriter::Write(short value)
    {
        WriteTemplate<short>(value);
    }

    void StreamWriter::Write(ushort value)
    {
        WriteTemplate<ushort>(value);
    }

    void StreamWriter::Write(int value)
    {
        WriteTemplate<int>(value);
    }

    void StreamWriter::Write(uint value)
    {
        WriteTemplate<uint>(value);
    }

    void StreamWriter::Write(long value)
    {
        WriteTemplate<long>(value);
    }

    void StreamWriter::Write(ulong value)
    {
        WriteTemplate<ulong>(value);
    }

    void StreamWriter::Write(int64 value)
    {
        WriteTemplate<int64>(value);
    }

    void StreamWriter::Write(uint64 value)
    {
        WriteTemplate<uint64>(value);
    }

    void StreamWriter::Write(float value)
    {
        WriteTemplate<float>(value);
    }

    void StreamWriter::Write(double value)
    {
        WriteTemplate<double>(value);
    }

    void StreamWriter::Write(const char* value)
    {
        Write(String(value));
    }

    void StreamWriter::Write(const String& value)
    {
        const int size = static_cast<int>(value.GetLength());
        Write(size);
        destination->Write(value.CStr(), size);
    }
}
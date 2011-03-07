#include <Halak/StreamReader.h>
#include <Halak/Assert.h>
#include <Halak/Stream.h>
#include <vector>

namespace Halak
{
    StreamReader::StreamReader(StreamPtr source)
        : source(source)
    {
    }

    StreamReader::~StreamReader()
    {
    }

    template <typename T> T StreamReader::ReadTemplate()
    {
        T result;
        const int readSize = source->Read(&result, sizeof(result));
        HKAssert(readSize == sizeof(result));
        return result;
    }

    bool StreamReader::ReadBool()
    {
        return ReadTemplate<bool>();
    }

    char StreamReader::ReadChar()
    {
        return ReadTemplate<char>();
    }

    uchar StreamReader::ReadUChar()
    {
        return ReadTemplate<uchar>();
    }

    short StreamReader::ReadShort()
    {
        return ReadTemplate<short>();
    }

    ushort StreamReader::ReadUShort()
    {
        return ReadTemplate<ushort>();
    }

    int StreamReader::ReadInt()
    {
        return ReadTemplate<int>();
    }

    uint StreamReader::ReadUInt()
    {
        return ReadTemplate<uint>();
    }

    long StreamReader::ReadLong()
    {
        return ReadTemplate<long>();
    }

    ulong StreamReader::ReadULong()
    {
        return ReadTemplate<ulong>();
    }

    int64 StreamReader::ReadInt64()
    {
        return ReadTemplate<int64>();
    }

    uint64 StreamReader::ReadUInt64()
    {
        return ReadTemplate<uint64>();
    }

    float StreamReader::ReadFloat()
    {
        return ReadTemplate<float>();
    }

    double StreamReader::ReadDouble()
    {
        return ReadTemplate<double>();
    }

    String StreamReader::ReadString()
    {
        const int size = ReadInt();
        std::vector<char> result;
        result.resize(size);
        source->Read(&result[0], size);
        return String(&result[0]);
    }

    template <> bool StreamReader::Read()
    {
        return ReadBool();
    }

    template <> char StreamReader::Read()
    {
        return ReadChar();
    }

    template <> uchar StreamReader::Read()
    {
        return ReadUChar();
    }

    template <> short StreamReader::Read()
    {
        return ReadShort();
    }

    template <> ushort StreamReader::Read()
    {
        return ReadUShort();
    }

    template <> int StreamReader::Read()
    {
        return ReadInt();
    }

    template <> uint StreamReader::Read()
    {
        return ReadUInt();
    }

    template <> long StreamReader::Read()
    {
        return ReadLong();
    }

    template <> ulong StreamReader::Read()
    {
        return ReadULong();
    }

    template <> int64 StreamReader::Read()
    {
        return ReadInt64();
    }

    template <> uint64 StreamReader::Read()
    {
        return ReadUInt64();
    }

    template <> float StreamReader::Read()
    {
        return ReadFloat();
    }

    template <> double StreamReader::Read()
    {
        return ReadDouble();
    }

    template <> String StreamReader::Read()
    {
        return ReadString();
    }
}
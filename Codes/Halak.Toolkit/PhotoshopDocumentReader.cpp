#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PhotoshopDocumentReader.h>
#include <Halak/Assert.h>
#include <Halak/String.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        PhotoshopDocumentReader::PhotoshopDocumentReader(const String& filename)
        {
            handle = CreateFile(filename.CStr(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (handle == INVALID_HANDLE_VALUE)
                handle = nullptr;

            DWORD fileSize = GetFileSize(handle, NULL);
            DWORD readSize = 0;
            buffer.resize(fileSize);
            ReadFile(handle, &buffer[0], buffer.size(), &readSize, nullptr);
            HKAssert(fileSize == readSize);
            position = 0;
        }
        
        PhotoshopDocumentReader::~PhotoshopDocumentReader()
        {
            if (handle)
                CloseHandle(handle);
        }

        char PhotoshopDocumentReader::ReadChar()
        {
            char v = '\0';

            memcpy(&v, &buffer[position], sizeof(v));
            position += sizeof(v);
            return v;
        }

        String PhotoshopDocumentReader::ReadChars(int size)
        {
            std::vector<char> result;
            result.resize(size);

            for (int i = 0; i < size; i++)
                result[i] = ReadChar();

            if (result.empty() == false)
                return String(&result[0], 0, result.size());
            else
                return String::Empty;
        }

        byte PhotoshopDocumentReader::ReadByte()
        {
            return buffer[position++];
        }

        std::vector<byte> PhotoshopDocumentReader::ReadBytes(int size)
        {
            static const std::vector<byte> Empty;

            std::vector<byte> v;
            v.resize(size);

            memcpy(&v[0], &buffer[position], v.size());
            position += v.size();
            return v;
        }

        short PhotoshopDocumentReader::ReadInt16()
        {
            short v = 0;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        unsigned short PhotoshopDocumentReader::ReadUInt16()
        {
            unsigned short v = 0;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        int PhotoshopDocumentReader::ReadInt32()
        {
            int v = 0;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        unsigned int PhotoshopDocumentReader::ReadUInt32()
        {
            unsigned int v = 0;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        float PhotoshopDocumentReader::ReadSingle()
        {
            float v = 0.0f;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        double PhotoshopDocumentReader::ReadDouble()
        {
            double v = 0.0;

            memcpy(&v, &buffer[position], sizeof(v));
            std::reverse(reinterpret_cast<byte*>(&v), reinterpret_cast<byte*>(&v) + sizeof(v));
            position += sizeof(v);
            return v;
        }

        uint32 PhotoshopDocumentReader::ReadFOURCC()
        {
            return ReadUInt32();
        }

        String PhotoshopDocumentReader::ReadPascalString()
        {
            const byte length = ReadByte();
            const String result = ReadChars(length);

            if ((length % 2) == 0)
                ReadByte();

            return result;
        }

        String PhotoshopDocumentReader::ReadPSDString()
        {
            const byte length = ReadByte();
            String psdString = ReadChars(length);

            return psdString;
        }

        String PhotoshopDocumentReader::ReadUnicodeString()
        {
            const uint length = ReadUInt32();

            std::vector<char> result;
            result.reserve(length * sizeof(ushort));

            for (uint i = 0; i < length; i++)
            {
                ushort c = ReadUInt16();
                if (c > 0x00FF)
                {
                    result.push_back(static_cast<char>((c & 0xFF00) >> 8));
                    result.push_back(static_cast<char>((c & 0x00FF) >> 0));
                }
                else
                    result.push_back(static_cast<char>(c));
            }

            return String(&result[0], 0, result.size());;
        }

        Rectangle PhotoshopDocumentReader::ReadRectangle()
        {
            Rectangle result = Rectangle::Empty;
            result.Y      = ReadInt32();
            result.X      = ReadInt32();
            result.Height = ReadInt32() - result.Y;
            result.Width  = ReadInt32() - result.X;
            return result;
        }

        std::vector<byte> PhotoshopDocumentReader::ReadRawPixelData(int width, int height, int bitsPerPixel)
        {
            switch (bitsPerPixel)
            {
                case 1:
                case 8:
                    return ReadBytes(width * height);
                case 16:
                    {
                        std::vector<byte> result;
                        result.resize(width * height);
                        for (std::vector<byte>::size_type i = 0; i < result.size(); i++)
                            result[i] = static_cast<byte>(ReadUInt16() >> 8);

                        return result;
                    }
                default:
                    throw std::exception();
            }
        }

        std::vector<byte> PhotoshopDocumentReader::ReadRLECompressedPixelData(int width, int height, int /*bitsPerPixel*/)
        {
            std::vector<byte> result;
            result.resize(width * height);

            const int size = static_cast<int>(result.size());
            for (int i = 0, bitmapOffset = 0; i < size; )
            {
                int length = static_cast<int>(ReadByte());
                if (length < 128)
                {
                    length++;
                    i += length;

                    for (int k = 0; k < length; k++, bitmapOffset++)
                        result[bitmapOffset] = ReadByte();
                }
                else if (length > 128)
                {
                    length ^= 0x0FF;
                    length += 2;
                    i += length;
                    byte compressedValue = ReadByte();

                    for (int k = 0; k < length; k++, bitmapOffset++)
                        result[bitmapOffset] = compressedValue;
                }
                // length == 128, 아무것도 안 합니다.
            }

            return result;
        }

        unsigned int PhotoshopDocumentReader::GetPosition()
        {
            //return SetFilePointer(handle, 0, NULL, FILE_CURRENT);

            return position;
        }

        void PhotoshopDocumentReader::SetPosition(unsigned int value)
        {
            //const LONG longDistance = static_cast<LONG>(value);
            //SetFilePointer(handle, longDistance, NULL, FILE_BEGIN);
            
            position = value;
        }

        void PhotoshopDocumentReader::Seek(unsigned int distance)
        {
            //const LONG longDistance = static_cast<LONG>(distance);
            //SetFilePointer(handle, longDistance, NULL, FILE_CURRENT);

            position += distance;
        }
    }
}
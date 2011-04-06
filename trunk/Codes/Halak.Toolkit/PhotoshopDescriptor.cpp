#include <Halak.Toolkit/PhotoshopDescriptor.h>
#include <Halak.Toolkit/PhotoshopDocumentReader.h>
#include <Halak/String.h>

namespace Halak
{
    namespace Toolkit
    {
        PhotoshopDescriptor::PhotoshopDescriptor(PhotoshopDocumentReader& reader)
        {
            String name = reader.ReadUnicodeString();
            uint length = reader.ReadUInt32();
            String key;
            if (length == 0)
                key = reader.ReadChars(4);
            else
                key = reader.ReadChars(length);
            uint count = reader.ReadUInt32();
            for (uint i = 0; i < count; i++)
            {
                uint len = reader.ReadUInt32();
                String keyName;
                if (len == 0)
                    keyName = reader.ReadChars(4);
                else
                    keyName = reader.ReadChars(len);

                String typeKey = reader.ReadChars(4);
            }
        }

        PhotoshopDescriptor::~PhotoshopDescriptor()
        {
        }
    }
}
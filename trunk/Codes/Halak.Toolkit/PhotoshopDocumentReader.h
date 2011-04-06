#pragma once
#ifndef __HALAK_TOOLKIT_PHOTOSHOPDOCUMENTREADER_H__
#define __HALAK_TOOLKIT_PHOTOSHOPDOCUMENTREADER_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/String.h>
#   include <Halak/Rectangle.h>
#   include <vector>
#   include <windows.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class PhotoshopDocumentReader
            {
                public:
                    PhotoshopDocumentReader(const Halak::String& filename);
                    virtual ~PhotoshopDocumentReader();

                    virtual char ReadChar();
                    virtual Halak::String ReadChars(int size);
                    virtual byte ReadByte();
                    virtual std::vector<byte> ReadBytes(int size);
                    virtual short ReadInt16();
                    virtual unsigned short ReadUInt16();
                    virtual int ReadInt32();
                    virtual unsigned int ReadUInt32();
                    virtual float ReadSingle();
                    virtual double ReadDouble();
                    virtual uint32 ReadFOURCC();
                    virtual Halak::String ReadPascalString();
                    virtual Halak::String ReadPSDString();
                    virtual Halak::String ReadUnicodeString();
                    virtual Rectangle ReadRectangle();
                    virtual std::vector<byte> ReadRawPixelData(int width, int height, int bitsPerPixel);
                    virtual std::vector<byte> ReadRLECompressedPixelData(int width, int height, int bitsPerPixel);

                    virtual unsigned int GetPosition();
                    virtual void SetPosition(unsigned int value);
                    virtual void Seek(unsigned int distance);

                private:
                    HANDLE handle;
                    std::vector<byte> buffer;
                    unsigned int position;
            };
        }
    }

#endif
#pragma once
#ifndef __HALAK_STREAMREADER_H__
#define __HALAK_STREAMREADER_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class StreamReader
        {
            public:
                StreamReader(StreamPtr source);
                virtual ~StreamReader();

                virtual bool ReadBool();
                virtual char ReadChar();
                virtual uchar ReadUChar();
                virtual short ReadShort();
                virtual ushort ReadUShort();
                virtual int ReadInt();
                virtual uint ReadUInt();
                virtual long ReadLong();
                virtual ulong ReadULong();
                virtual int64 ReadInt64();
                virtual uint64 ReadUInt64();
                virtual float ReadFloat();
                virtual double ReadDouble();
                virtual String ReadString();
                template <typename T> T Read();

            private:
                template <typename T> inline T ReadTemplate();

            protected:
                StreamPtr source;
        };
    }

#   include <Halak/StreamReader.inl>

#endif
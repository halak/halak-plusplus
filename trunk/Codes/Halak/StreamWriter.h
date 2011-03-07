#pragma once
#ifndef __HALAK_STREAMWRITER_H__
#define __HALAK_STREAMWRITER_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class StreamWriter
        {
            public:
                StreamWriter(StreamPtr destination);
                virtual ~StreamWriter();

                virtual void Write(bool value);
                virtual void Write(char value);
                virtual void Write(uchar value);
                virtual void Write(short value);
                virtual void Write(ushort value);
                virtual void Write(int value);
                virtual void Write(uint value);
                virtual void Write(long value);
                virtual void Write(ulong value);
                virtual void Write(int64 value);
                virtual void Write(uint64 value);
                virtual void Write(float value);
                virtual void Write(double value);
                virtual void Write(const char* value);
                virtual void Write(const String& value);

            private:
                template <typename T> inline void WriteTemplate(T value);

            protected:
                StreamPtr destination;
        };
    }

#endif
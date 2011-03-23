#pragma once
#ifndef __HALAK_STREAM_H__
#define __HALAK_STREAM_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class Stream : public SharedObject
        {
            public:
                virtual ~Stream();

                virtual int Read(void* buffer, int size) = 0;
                virtual int Write(const void* buffer, int size) = 0;
                virtual void Flush() = 0;

                virtual String ReadText();

                virtual bool CanRead() const = 0;
                virtual bool CanWrite() const = 0;

            protected:
                Stream();

            private:
                Stream(const Stream&);
                Stream& operator = (const Stream&);
        };
    }

#endif
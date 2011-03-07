#pragma once
#ifndef __HALAK_JSONSTREAMWRITER_H__
#define __HALAK_JSONSTREAMWRITER_H__

#   include <Halak/FWD.h>
#   include <Halak/StreamWriter.h>

    namespace Halak
    {
        class JSONStreamWriter : public StreamWriter
        {
            public:
                JSONStreamWriter(StreamPtr destination);
                virtual ~JSONStreamWriter();

            private:
        };
    }

#endif
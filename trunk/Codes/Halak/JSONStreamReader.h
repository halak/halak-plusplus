#pragma once
#ifndef __HALAK_JSONSTREAMREADER_H__
#define __HALAK_JSONSTREAMREADER_H__

#   include <Halak/FWD.h>
#   include <Halak/StreamReader.h>

    namespace Halak
    {
        class JSONStreamReader : public StreamReader
        {
            public:
                JSONStreamReader(StreamPtr source);
                virtual ~JSONStreamReader();

            private:
        };
    }

#endif
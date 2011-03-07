#pragma once
#ifndef __HALAK_BINARYSTREAMREADER_H__
#define __HALAK_BINARYSTREAMREADER_H__

#   include <Halak/FWD.h>
#   include <Halak/StreamReader.h>

    namespace Halak
    {
        class BinaryStreamReader : public StreamReader
        {
            public:
                BinaryStreamReader(StreamPtr source);
                virtual ~BinaryStreamReader();

            private:
        };
    }

#endif
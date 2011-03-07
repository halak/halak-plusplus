#pragma once
#ifndef __HALAK_BINARYSTREAMWRITER_H__
#define __HALAK_BINARYSTREAMWRITER_H__

#   include <Halak/FWD.h>
#   include <Halak/StreamWriter.h>

    namespace Halak
    {
        class BinaryStreamWriter : public StreamWriter
        {
            public:
                BinaryStreamWriter(StreamPtr destination);
                virtual ~BinaryStreamWriter();

            private:
        };
    }

#endif
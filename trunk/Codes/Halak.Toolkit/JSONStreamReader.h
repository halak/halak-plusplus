#pragma once
#ifndef __HALAK_TOOLKIT_JSONSTREAMREADER_H__
#define __HALAK_TOOLKIT_JSONSTREAMREADER_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/StreamReader.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class JSONStreamReader : public StreamReader
            {
                public:
                    JSONStreamReader(StreamPtr source);
                    virtual ~JSONStreamReader();

                private:
            };
        }
    }

#endif
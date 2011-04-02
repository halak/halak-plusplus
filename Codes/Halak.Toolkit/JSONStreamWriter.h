#pragma once
#ifndef __HALAK_TOOLKIT_JSONSTREAMWRITER_H__
#define __HALAK_TOOLKIT_JSONSTREAMWRITER_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/StreamWriter.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class JSONStreamWriter : public StreamWriter
            {
                public:
                    JSONStreamWriter(StreamPtr destination);
                    virtual ~JSONStreamWriter();

                private:
            };
        }
    }

#endif
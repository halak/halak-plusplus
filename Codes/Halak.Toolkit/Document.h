#pragma once
#ifndef __HALAK_WXTOOLKIT_DOCUMENT_H__
#define __HALAK_WXTOOLKIT_DOCUMENT_H__

#   include <Halak.wxToolkit/FWD.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class Document : public SharedObject
            {
                public:
                    Document();
                    virtual ~Document();
            };
        }
    }

#endif
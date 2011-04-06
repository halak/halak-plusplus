#pragma once
#ifndef __HALAK_TOOLKIT_PHOTOSHOPDESCRIPTOR_H__
#define __HALAK_TOOLKIT_PHOTOSHOPDESCRIPTOR_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Asset.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class PhotoshopDescriptor : public Asset
            {
                public:
                    PhotoshopDescriptor(PhotoshopDocumentReader& reader);
                    virtual ~PhotoshopDescriptor();

                private:
            };
        }
    }

#endif
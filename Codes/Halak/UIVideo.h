#pragma once
#ifndef __HALAK_UIVIDEO_H__
#define __HALAK_UIVIDEO_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UIVideo : public UIVisual
        {
            public:
                UIVideo();
                virtual ~UIVideo();

            private:
        };
    }

#   include <Halak/UIVideo.inl>

#endif
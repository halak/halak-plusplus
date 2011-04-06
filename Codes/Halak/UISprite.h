#pragma once
#ifndef __HALAK_UISPRITE_H__
#define __HALAK_UISPRITE_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UISprite : public UIVisual
        {
            public:
                UISprite();
                virtual ~UISprite();

            private:
        };
    }

#   include <Halak/UISprite.inl>

#endif
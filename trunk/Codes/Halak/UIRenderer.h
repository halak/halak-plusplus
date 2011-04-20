#pragma once
#ifndef __HALAK_UIRENDERER_H__
#define __HALAK_UIRENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIRenderer : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'R', 'R');
            public:
                UIRenderer();
                virtual ~UIRenderer();
        };
    }

#   include <Halak/UIRenderer.inl>

#endif
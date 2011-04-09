#pragma once
#ifndef __HALAK_UIRENDERER_H__
#define __HALAK_UIRENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIRenderer : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'R', 'N');
            public:
                UIRenderer();
                UIRenderer(SpriteRenderer* spriteRenderer);
                virtual ~UIRenderer();

                inline SpriteRenderer* GetSpriteRenderer() const;
                inline void SetSpriteRenderer(SpriteRenderer* value);

            private:
                SpriteRenderer* spriteRenderer;
        };
    }

#endif
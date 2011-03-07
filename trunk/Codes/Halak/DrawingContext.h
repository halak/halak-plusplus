#pragma once
#ifndef __HALAK_DRAWINGCONTEXT_H__
#define __HALAK_DRAWINGCONTEXT_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class DrawingContext
        {
            public:
                DrawingContext(SpriteRenderer* spriteRenderer);
                ~DrawingContext();

                inline SpriteRenderer* GetSpriteRenderer() const;

            private:
                SpriteRenderer* spriteRenderer;
        };
    }

#   include <Halak/DrawingContext.inl>

#endif
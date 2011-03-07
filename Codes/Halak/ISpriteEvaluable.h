#pragma once
#ifndef __HALAK_SPRITEEVALUABLE_INTERFACE__
#define __HALAK_SPRITEEVALUABLE_INTERFACE__

#   include <Halak/FWD.h>
#   include <Halak/Sprite.h>

    namespace Halak
    {
        class ISpriteEvaluable
        {
            public:
                virtual ~ISpriteEvaluable() { }
                virtual Sprite Evaluate() = 0;
        };
    }

#endif
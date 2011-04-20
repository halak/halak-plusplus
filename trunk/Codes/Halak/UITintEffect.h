#pragma once
#ifndef __HALAK_UITINTEFFECT_H__
#define __HALAK_UITINTEFFECT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEffect.h>

    namespace Halak
    {
        class UITintEffect : public UIEffect
        {
            public:
                UITintEffect();
                virtual ~UITintEffect();

            private:
        };
    }

#   include <Halak/UITintEffect.inl>

#endif
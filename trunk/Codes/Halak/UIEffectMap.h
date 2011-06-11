#pragma once
#ifndef __HALAK_UIEFFECTMAP_H__
#define __HALAK_UIEFFECTMAP_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>

    namespace Halak
    {
        class UIEffectMap : public SharedObject
        {
            public:
                UIEffectMap();
                virtual ~UIEffectMap();

            private:
        };
    }

#   include <Halak/UIEffectMap.inl>

#endif
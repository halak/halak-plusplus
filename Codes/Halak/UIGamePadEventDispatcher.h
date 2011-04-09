#pragma once
#ifndef __HALAK_UIGAMEPADEVENTDISPATCHER_H__
#define __HALAK_UIGAMEPADEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIGamePadEventDispatcher : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'G', 'P');
            public:
                UIGamePadEventDispatcher();
                virtual ~UIGamePadEventDispatcher();

            private:
        };
    }

#   include <Halak/UIGamePadEventDispatcher.inl>

#endif
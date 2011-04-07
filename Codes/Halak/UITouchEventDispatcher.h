#pragma once
#ifndef __HALAK_UITOUCHEVENTDISPATCHER_H__
#define __HALAK_UITOUCHEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UITouchEventDispatcher : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('U', 'I', 'T', 'H');
            public:
                UITouchEventDispatcher();
                virtual ~UITouchEventDispatcher();

            private:
        };
    }

#   include <Halak/UITouchEventDispatcher.inl>

#endif
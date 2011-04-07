#pragma once
#ifndef __HALAK_UIEVENTDISPATCHER_H__
#define __HALAK_UIEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIEventDispatcher : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('U', 'I', 'E', 'D');
            public:
                UIEventDispatcher();
                virtual ~UIEventDispatcher();

            private:
        };
    }

#   include <Halak/UIEventDispatcher.inl>

#endif
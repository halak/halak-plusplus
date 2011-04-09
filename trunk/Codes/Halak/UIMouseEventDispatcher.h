#pragma once
#ifndef __HALAK_UIMOUSEEVENTDISPATCHER_H__
#define __HALAK_UIMOUSEEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIMouseEventDispatcher : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'M', 'S');
            public:
                UIMouseEventDispatcher();
                virtual ~UIMouseEventDispatcher();

            private:
        };
    }

#   include <Halak/UIMouseEventDispatcher.inl>

#endif
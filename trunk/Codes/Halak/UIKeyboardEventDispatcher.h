#pragma once
#ifndef __HALAK_UIKEYBOARDEVENTDISPATCHER_H__
#define __HALAK_UIKEYBOARDEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIKeyboardEventDispatcher : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'K', 'B');
            public:
                UIKeyboardEventDispatcher();
                virtual ~UIKeyboardEventDispatcher();

            private:
        };
    }

#   include <Halak/UIKeyboardEventDispatcher.inl>

#endif
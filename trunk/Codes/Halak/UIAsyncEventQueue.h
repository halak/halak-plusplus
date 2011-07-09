#pragma once
#ifndef __HALAK_UIASYNCEVENTQUEUE_H__
#define __HALAK_UIASYNCEVENTQUEUE_H__

#   include <Halak/FWD.h>
#   include <Halak/UpdateableGameComponent.h>
#   include <vector>

    namespace Halak
    {
        class UIAsyncEventQueue : public UpdateableGameComponent
        {
            HKClassFOURCC('U', 'A', 'E', 'Q');
            public:
                typedef std::pair<UIEventHandlerPtr, UIEventArgsPtr> EventHandlerArgsPair;
                typedef std::vector<EventHandlerArgsPair> ItemCollection;

            public:
                UIAsyncEventQueue();
                virtual ~UIAsyncEventQueue();

                virtual void Update(float dt, uint timestamp);

                void NotifyAll();
   
                void Enqueue(UIEventHandler* item, const UIEventArgs& args);

            private:
                Timeline* timeline;
                ItemCollection items;
        };
    }

#   include <Halak/UIAsyncEventQueue.inl>

#endif
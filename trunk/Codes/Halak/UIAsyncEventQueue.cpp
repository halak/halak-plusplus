#include <Halak/PCH.h>
#include <Halak/UIAsyncEventQueue.h>
#include <Halak/Timeline.h>
#include <Halak/UIEventArgs.h>
#include <Halak/UIEventHandler.h>

namespace Halak
{
    UIAsyncEventQueue::UIAsyncEventQueue()
    {
    }

    UIAsyncEventQueue::~UIAsyncEventQueue()
    {
    }

    void UIAsyncEventQueue::Update(float /*dt*/, uint /*timestamp*/)
    {
        NotifyAll();
    }

    void UIAsyncEventQueue::NotifyAll()
    {
        ItemCollection temporaryItems;
        temporaryItems.swap(items);

        for (ItemCollection::const_iterator it = temporaryItems.begin(); it != temporaryItems.end(); it++)
            (*it).first->Invoke(*(*it).second);
    }
   
    void UIAsyncEventQueue::Enqueue(UIEventHandler* item, const UIEventArgs& args)
    {
        items.push_back(EventHandlerArgsPair(item, args.Clone()));
    }

    Timeline* UIAsyncEventQueue::GetTimeline() const
    {
        return timeline;
    }

    void UIAsyncEventQueue::SetTimeline(Timeline* value)
    {
        if (timeline != value)
        {
            if (timeline)
                timeline->Remove(this);

            timeline = value;

            if (timeline)
                timeline->Add(this);
        }
    }
}
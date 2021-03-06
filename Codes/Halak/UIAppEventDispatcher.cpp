#include <Halak/PCH.h>
#include <Halak/UIAppEventDispatcher.h>
#include <Halak/UIEventMap.h>

namespace Halak
{
    UIAppEventDispatcher::UIAppEventDispatcher()
    {
    }

    UIAppEventDispatcher::~UIAppEventDispatcher()
    {
    }

    void UIAppEventDispatcher::RaiseEvent(const UIEventID& id, const UIEventArgs& args) const
    {
        HKAssert(id.GetType() == UIEventID::ApplicationType);

        SubscriptionMap::const_iterator itBegin = subscriptionTable.lower_bound(id);
        SubscriptionMap::const_iterator itEnd = subscriptionTable.upper_bound(id);
        for (SubscriptionMap::const_iterator it = itBegin; it != itEnd; it++)
            (*it).second->RaiseEvent(id, args);
    }
    
    void UIAppEventDispatcher::Subscribe(UIEventMap* subscriber, const UIEventID& id)
    {
        // 이 함수를 호출하는 UIEventMap에서 중복된 UIEventID는 구독을 요청하지 않는다.
        // 하지만 Bug가 있을 수 있으니 Debug Build에서는 확인을 해본다.

        SubscriptionMap::iterator itBegin = subscriptionTable.lower_bound(id);

#       if (defined(HALAK_DEBUG))
            if (itBegin != subscriptionTable.end())
            {
                SubscriptionMap::iterator itEnd = subscriptionTable.upper_bound(id);
                for (SubscriptionMap::const_iterator it = itBegin; it != itEnd; it++)
                {
                    HKAssertDebug((*it).second == subscriber);
                }
            }
#       endif

        subscriptionTable.insert(itBegin, SubscriptionMap::value_type(id, subscriber));
    }

    void UIAppEventDispatcher::Unsubscribe(UIEventMap* subscriber, const UIEventID& id)
    {
        SubscriptionMap::iterator it = subscriptionTable.lower_bound(id);
        HKAssertDebug(it != subscriptionTable.end());

        SubscriptionMap::iterator itEnd = subscriptionTable.upper_bound(id);
        for(; it != itEnd; it++)
        {
            if ((*it).second == subscriber)
            {
                subscriptionTable.erase(it);
                break;
            }
        }
    }

    void UIAppEventDispatcher::UnsubscribeAll(UIEventMap* subscriber)
    {
        for (SubscriptionMap::iterator it = subscriptionTable.begin(); it != subscriptionTable.end();)
        {
            if ((*it).second == subscriber)
                subscriptionTable.erase(it++);
            else
                it++;
        }
    }
}
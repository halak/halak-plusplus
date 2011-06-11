#pragma once
#ifndef __HALAK_UIAPPEVENTDISPATCHER_H__
#define __HALAK_UIAPPEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventDispatcher.h>
#   include <Halak/UIEventID.h>
#   include <map>

    namespace Halak
    {
        class UIAppEventDispatcher : public UIEventDispatcher
        {
            HKClassFOURCC('U', 'I', 'A', 'P');
            public:
                typedef std::multimap<UIEventID, UIEventMap*> SubscriptionMap;

            public:
                UIAppEventDispatcher();
                virtual ~UIAppEventDispatcher();

                void RaiseEvent(const UIEventID& id, const UIEventArgs& args) const;

            private:
                friend class UIEventMap;
                void Subscribe(UIEventMap* subscriber, const UIEventID& id);
                void Unsubscribe(UIEventMap* subscriber, const UIEventID& id);
                void UnsubscribeAll(UIEventMap* subscriber);

            private:
                SubscriptionMap subscriptionTable;
        };
    }

#   include <Halak/UIAppEventDispatcher.inl>

#endif
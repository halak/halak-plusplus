#pragma once
#ifndef __HALAK_UISEQUENTIALEVENTHANDLER_H__
#define __HALAK_UISEQUENTIALEVENTHANDLER_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventHandler.h>
#   include <vector>

    namespace Halak
    {
        class UISequentialEventHandler : public UIEventHandler
        {
            public:
                typedef std::vector<UIEventHandlerPtr> HandlerCollection;

            public:
                UISequentialEventHandler();
                UISequentialEventHandler(UIEventHandler* first, UIEventHandler* second);
                explicit UISequentialEventHandler(int initialCapacity);
                virtual ~UISequentialEventHandler();

                virtual bool Invoke(const UIEventArgs& args);

                void Add(UIEventHandler* item);
                void Insert(int index, UIEventHandler* item);
                bool Remove(UIEventHandler* item);
                void RemoveAt(int index);
                void Clear();

                inline const HandlerCollection& GetHandlers() const;
                void SetHandlers(const HandlerCollection& value);
                void MoveHandlers(HandlerCollection& value);

                virtual bool IsSequence() const;

            private:
                HandlerCollection handlers;
        };
    }

#   include <Halak/UISequentialEventHandler.inl>

#endif
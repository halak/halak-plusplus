#pragma once
#ifndef __HALAK_UIEVENTHANDLER_H__
#define __HALAK_UIEVENTHANDLER_H__

#   include <Halak/FWD.h>
#   include <Halak/UIElement.h>

    namespace Halak
    {
        class UIEventHandler : public UIElement
        {
            public:
                virtual ~UIEventHandler();

                virtual bool Invoke(const UIEventArgs& args) = 0;

                virtual bool IsSequence() const;

            protected:
                UIEventHandler();
        };
    }

#   include <Halak/UIEventHandler.inl>

#endif
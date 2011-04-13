#pragma once
#ifndef __HALAK_UIBUTTON_H__
#define __HALAK_UIBUTTON_H__

#   include <Halak/FWD.h>
#   include <Halak/UIWindow.h>

    namespace Halak
    {
        class UIButton : public UIWindow
        {
            public:
                UIButton();
                virtual ~UIButton();

            protected:
                virtual bool OnMouseEnter(const UIMouseEventArgs& args);
                virtual bool OnMouseLeave(const UIMouseEventArgs& args);
                virtual bool OnMouseLeftDown(const UIMouseEventArgs& args);
                virtual bool OnMouseLeftUp(const UIMouseEventArgs& args);

            private:
        };
    }

#   include <Halak/UIButton.inl>

#endif
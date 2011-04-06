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

            private:
        };
    }

#   include <Halak/UIButton.inl>

#endif
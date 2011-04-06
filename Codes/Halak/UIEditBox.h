#pragma once
#ifndef __HALAK_UIEDITBOX_H__
#define __HALAK_UIEDITBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIWindow.h>

    namespace Halak
    {
        class UIEditBox : public UIWindow
        {
            public:
                UIEditBox();
                virtual ~UIEditBox();

            private:
        };
    }

#   include <Halak/UIEditBox.inl>

#endif
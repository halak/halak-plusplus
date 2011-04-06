#pragma once
#ifndef __HALAK_UILISTBOX_H__
#define __HALAK_UILISTBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIWindow.h>

    namespace Halak
    {
        class UIListBox : public UIWindow
        {
            public:
                UIListBox();
                virtual ~UIListBox();

            private:
        };
    }

#   include <Halak/UIListBox.inl>

#endif
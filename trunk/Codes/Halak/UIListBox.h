#pragma once
#ifndef __HALAK_UILISTBOX_H__
#define __HALAK_UILISTBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFlowPanel.h>

    namespace Halak
    {
        class UIListBox : public UIFlowPanel
        {
            public:
                UIListBox();
                virtual ~UIListBox();

            private:
        };
    }

#   include <Halak/UIListBox.inl>

#endif
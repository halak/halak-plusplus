#pragma once
#ifndef __HALAK_UIFLOWPANEL_H__
#define __HALAK_UIFLOWPANEL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIWindow.h>

    namespace Halak
    {
        class UIFlowPanel : public UIWindow
        {
            public:
                UIFlowPanel();
                virtual ~UIFlowPanel();

            private:
        };
    }

#   include <Halak/UIFlowPanel.inl>

#endif
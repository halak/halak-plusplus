#pragma once
#ifndef __HALAK_UIMARKUPTEXTBOX_H__
#define __HALAK_UIMARKUPTEXTBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFlowPanel.h>

    namespace Halak
    {
        class UIMarkupTextBox : public UIFlowPanel
        {
            public:
                UIMarkupTextBox();
                virtual ~UIMarkupTextBox();

            private:
        };
    }

#   include <Halak/UIMarkupTextBox.inl>

#endif
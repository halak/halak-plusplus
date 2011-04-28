#pragma once
#ifndef __HALAK_UIMARKUPTEXTBOX_H__
#define __HALAK_UIMARKUPTEXTBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFlowPanel.h>
#   include <Halak/UIMarkupText.h>

    namespace Halak
    {
        class UIMarkupTextBox : public UIFlowPanel
        {
            public:
                UIMarkupTextBox();
                virtual ~UIMarkupTextBox();

                inline const UIMarkupText& GetText() const;
                void SetText(const UIMarkupText& value);

                inline Font* GetFont() const;
                void SetFont(Font* value);

            private:
                void UpdateLayout();

            private:
                UIMarkupText text;
                FontPtr font;
        };
    }

#   include <Halak/UIMarkupTextBox.inl>

#endif
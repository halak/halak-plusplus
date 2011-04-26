#pragma once
#ifndef __HALAK_UICHECKBOX_H__
#define __HALAK_UICHECKBOX_H__

#   include <Halak/FWD.h>
#   include <Halak/UIButton.h>

    namespace Halak
    {
        class UICheckBox : public UIButton
        {
            public:
                UICheckBox();
                virtual ~UICheckBox();

                inline UIWindow* GetCheckedNormalWindow() const;
                inline UIWindow* GetCheckedPushedWindow() const;
                inline UIWindow* GetCheckedHoveringWindow() const;

                inline bool GetChecked() const;
                void SetChecked(bool value);

            protected:
                virtual UIWindow* OnUpdateLayout();

                virtual bool OnMouseClick(const UIMouseEventArgs& args);

            private:
                UIWindowPtr checkedNormalWindow;
                UIWindowPtr checkedPushedWindow;
                UIWindowPtr checkedHoveringWindow;
                bool checked;
        };
    }

#   include <Halak/UICheckBox.inl>

#endif
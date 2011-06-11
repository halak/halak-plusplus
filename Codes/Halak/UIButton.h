#pragma once
#ifndef __HALAK_UIBUTTON_H__
#define __HALAK_UIBUTTON_H__

#   include <Halak/FWD.h>
#   include <Halak/UIPanel.h>

    namespace Halak
    {
        class UIButton : public UIPanel
        {
            public:
                enum State
                {
                    NormalState,
                    PushedState,
                    HoveringState,
                };

            public:
                UIButton();
                virtual ~UIButton();

                inline State GetCurrentState() const;
                inline UIWindow* GetNormalWindow() const;
                inline UIWindow* GetPushedWindow() const;
                inline UIWindow* GetHoveringWindow() const;
                inline UIWindow* GetCurrentWindow() const;

                inline bool GetHideInactives() const;
                void SetHideInactives(bool value);

            protected:
                void UpdateLayout();
                virtual UIWindow* OnUpdateLayout();

                virtual void OnMouseEnter(const UIMouseEventArgs& args);
                virtual void OnMouseLeave(const UIMouseEventArgs& args);
                virtual bool OnMouseButtonDown(const UIMouseButtonEventArgs& args);
                virtual bool OnMouseButtonUp(const UIMouseButtonEventArgs& args);

            private:
                void SetCurrentState(State value);

            private:
                State currentState;
                UIWindowPtr normalWindow;
                UIWindowPtr pushedWindow;
                UIWindowPtr hoveringWindow;
                UIWindowPtr currentWindow;
                bool hideInactives;
        };
    }

#   include <Halak/UIButton.inl>

#endif
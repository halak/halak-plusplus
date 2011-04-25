#include <Halak/PCH.h>
#include <Halak/UIButton.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIMouseButtonEventArgs.h>

namespace Halak
{
    UIButton::UIButton()
        : UIWindow(),
          currentState(NormalState),
          normalWindow(new UIWindow()),
          pushedWindow(new UIWindow()),
          hoveringWindow(new UIWindow()),
          hideInactives(true)
    {
        normalWindow->SetFrame(new UIFittedFrame());
        normalWindow->Show();
        pushedWindow->SetFrame(new UIFittedFrame());
        pushedWindow->Hide();
        hoveringWindow->SetFrame(new UIFittedFrame());
        hoveringWindow->Hide();
        AddChild(hoveringWindow);
        AddChild(pushedWindow);
        AddChild(normalWindow);
    }

    UIButton::~UIButton()
    {
    }

    void UIButton::SetCurrentState(State value)
    {
        if (currentState != value)
        {
            currentState = value;

            struct UpdateLayout
            {
                static void Do(UIWindow* active, UIWindow* inactive1, UIWindow* inactive2, bool hideInactives)
                {
                    active->BringToFront();
                    active->Show();

                    if (hideInactives)
                    {
                        inactive1->Hide();
                        inactive2->Hide();
                    }
                }
            };

            switch (value)
            {
                case NormalState:
                    UpdateLayout::Do(normalWindow, pushedWindow, hoveringWindow, hideInactives);
                    break;
                case PushedState:
                    UpdateLayout::Do(pushedWindow, normalWindow, hoveringWindow, hideInactives);
                    break;
                case HoveringState:
                    UpdateLayout::Do(hoveringWindow, normalWindow, pushedWindow, hideInactives);
                    break;
            }
        }
    }

    void UIButton::SetHideInactives(bool value)
    {
        if (hideInactives != value)
        {
            hideInactives = value;

            if (value)
            {
                switch (currentState)
                {
                    case NormalState:
                        pushedWindow->Hide();
                        hoveringWindow->Hide();
                        break;
                    case PushedState:
                        normalWindow->Hide();
                        hoveringWindow->Hide();
                        break;
                    case HoveringState:
                        normalWindow->Hide();
                        pushedWindow->Hide();
                        break;
                }
            }
        }
    }
    
    void UIButton::OnMouseEnter(const UIMouseEventArgs& /*args*/)
    {
        SetCurrentState(HoveringState);
    }

    void UIButton::OnMouseLeave(const UIMouseEventArgs& /*args*/)
    {
        SetCurrentState(NormalState);
    }

    bool UIButton::OnMouseButtonDown(const UIMouseButtonEventArgs& args)
    {
        if (args.GetButtonCode() == Key::MouseLeftButton)
            SetCurrentState(PushedState);

        return false;
    }

    bool UIButton::OnMouseButtonUp(const UIMouseButtonEventArgs& args)
    {
        if (args.GetButtonCode() == Key::MouseLeftButton)
            SetCurrentState(HoveringState);

        return false;
    }
}
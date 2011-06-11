#include <Halak/PCH.h>
#include <Halak/UIButton.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIMouseButtonEventArgs.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIButton::UIButton()
        : currentState(NormalState),
          normalWindow(new UIWindow()),
          pushedWindow(new UIWindow()),
          hoveringWindow(new UIWindow()),
          currentWindow(normalWindow),
          hideInactives(true)
    {
        normalWindow->SetFrame(new UIFittedFrame());
        normalWindow->Show();
        pushedWindow->SetFrame(new UIFittedFrame());
        pushedWindow->Hide();
        hoveringWindow->SetFrame(new UIFittedFrame());
        hoveringWindow->Hide();
        Add(hoveringWindow);
        Add(pushedWindow);
        Add(normalWindow);
    }

    UIButton::~UIButton()
    {
    }

    void UIButton::SetCurrentState(State value)
    {
        if (currentState != value)
        {
            currentState = value;
            UpdateLayout();
        }
    }

    void UIButton::SetHideInactives(bool value)
    {
        if (hideInactives != value)
        {
            hideInactives = value;
            UpdateLayout();
        }
    }

    void UIButton::UpdateLayout()
    {
        currentWindow = OnUpdateLayout();
    }

    UIWindow* UIButton::OnUpdateLayout()
    {
        UIWindow* activeWindow = nullptr;
        switch (currentState)
        {
            case NormalState:
                activeWindow = normalWindow;
                break;
            case PushedState:
                activeWindow = pushedWindow;
                break;
            case HoveringState:
                activeWindow = hoveringWindow;
                break;
        }

        activeWindow->BringToFront();
        activeWindow->Show();

        if (GetHideInactives())
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

        return activeWindow;
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
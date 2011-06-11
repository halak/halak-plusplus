#include <Halak/PCH.h>
#include <Halak/UICheckBox.h>
#include <Halak/UIFittedFrame.h>
#include <Halak/UIMouseEventArgs.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UICheckBox::UICheckBox()
        : checkedNormalWindow(new UIWindow()),
          checkedPushedWindow(new UIWindow()),
          checkedHoveringWindow(new UIWindow()),
          checked(false)
    {
        checkedNormalWindow->SetFrame(new UIFittedFrame());
        checkedNormalWindow->Hide();
        checkedPushedWindow->SetFrame(new UIFittedFrame());
        checkedPushedWindow->Hide();
        checkedHoveringWindow->SetFrame(new UIFittedFrame());
        checkedHoveringWindow->Hide();
        Add(checkedHoveringWindow);
        Add(checkedPushedWindow);
        Add(checkedNormalWindow);
    }

    UICheckBox::~UICheckBox()
    {
    }

    void UICheckBox::SetChecked(bool value)
    {
        if (checked != value)
        {
            checked = value;
            UpdateLayout();
        }
    }

    UIWindow* UICheckBox::OnUpdateLayout()
    {
        UIWindow* const windows[] = 
        {
            GetNormalWindow(), GetPushedWindow(), GetHoveringWindow(),
            checkedNormalWindow, checkedPushedWindow, checkedHoveringWindow,
        };
        HKStaticAssert(NormalState == 0 && PushedState == 1 && HoveringState == 2);

        const int activeWindowIndex = static_cast<int>(GetCurrentState()) + ((checked) ? 3 : 0);
        HKAssertDebug(0 <= activeWindowIndex && activeWindowIndex < sizeof(windows) / sizeof(windows[0]));
        UIWindow* activeWindow = windows[activeWindowIndex];

        activeWindow->BringToFront();
        activeWindow->Show();

        if (GetHideInactives())
        {
            for (int i = 0; i < sizeof(windows) / sizeof(windows[0]); i++)
            {
                if (i != activeWindowIndex)
                    windows[i]->Hide();
            }
        }

        return activeWindow;
    }

    bool UICheckBox::OnMouseClick(const UIMouseEventArgs& /*args*/)
    {
        checked = !checked;
        UpdateLayout();
        return false;
    }
}
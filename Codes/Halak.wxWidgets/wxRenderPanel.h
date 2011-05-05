#pragma once
#ifndef __HALAK_WXWIDGETS_WXRENDERPANEL_H__
#define __HALAK_WXWIDGETS_WXRENDERPANEL_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxRenderPanel : public wxPanel
            {
                public:
                    wxRenderPanel(wxWindow* parent);
                    virtual ~wxRenderPanel();

                    DisplaySwapChain* GetSwapChain() const;
                    void SetSwapChain(DisplaySwapChain* value);

                protected:
                    void OnIdle(wxTimerEvent& event);
                    void OnDraw(wxEraseEvent& event);
                    void OnSize(wxSizeEvent& event);
                    void OnScrollWin(wxScrollWinEvent& event);

                protected:
                    virtual void Draw();

                private:
                    DisplaySwapChain* swapChain;

                    wxTimer idleTimer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
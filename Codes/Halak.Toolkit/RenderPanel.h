#pragma once
#ifndef __HALAK_WXTOOLKIT_WXRENDERPANEL_H__
#define __HALAK_WXTOOLKIT_WXRENDERPANEL_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class RenderPanel : public wxPanel
            {
                public:
                    RenderPanel(wxWindow* parent);
                    virtual ~RenderPanel();

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
                    Halak::DisplaySwapChain* swapChain;

                    wxTimer idleTimer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
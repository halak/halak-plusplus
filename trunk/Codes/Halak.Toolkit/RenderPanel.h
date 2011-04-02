#pragma once
#ifndef __HALAK_TOOLKIT_WXRENDERPANEL_H__
#define __HALAK_TOOLKIT_WXRENDERPANEL_H__

#   include <Halak.Toolkit/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace Toolkit
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
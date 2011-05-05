#pragma once
#ifndef __HALAK_WXWIDGETS_PALETTEWINDOW_H__
#define __HALAK_WXWIDGETS_PALETTEWINDOW_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxPaletteWindow : public wxPanel
            {
                public:
                    wxPaletteWindow(wxWindow* parent);

                protected:
                    void OnCloseWindow(wxCloseEvent& event);

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
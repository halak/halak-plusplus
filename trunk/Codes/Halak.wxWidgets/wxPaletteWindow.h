#pragma once
#ifndef __HALAK_WXWIDGETS_PALETTEWINDOW_H__
#define __HALAK_WXWIDGETS_PALETTEWINDOW_H__

#   include <Halak.Toolkit/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class PaletteWindow : public wxPanel
            {
                public:
                    PaletteWindow(wxWindow* parent);

                protected:
                    void OnCloseWindow(wxCloseEvent& event);

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
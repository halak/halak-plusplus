#pragma once
#ifndef __HALAK_WXTOOLKIT_PALETTEWINDOW_H__
#define __HALAK_WXTOOLKIT_PALETTEWINDOW_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class PaletteWindow : public wxPanel
            {
                public:
                    PaletteWindow(wxWindow* parent, ServiceTree* services);

                protected:
                    void OnCloseWindow(wxCloseEvent& event);

                private:
                    ServiceTree* services;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
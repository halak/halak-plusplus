#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/wxPaletteWindow.h>

namespace Halak
{
    namespace wxWidgets
    {
        BEGIN_EVENT_TABLE(wxPaletteWindow, wxPanel)
            EVT_CLOSE(wxPaletteWindow::OnCloseWindow)
        END_EVENT_TABLE()

        wxPaletteWindow::wxPaletteWindow(wxWindow* parent)
            : wxPanel(parent, wxID_ANY)
        {
        }

        void wxPaletteWindow::OnCloseWindow(wxCloseEvent& event)
        {
            Show(false);
            event.Veto();
        }
    }
}
#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PaletteWindow.h>

namespace Halak
{
    namespace wxWidgets
    {
        BEGIN_EVENT_TABLE(PaletteWindow, wxPanel)
            EVT_CLOSE(PaletteWindow::OnCloseWindow)
        END_EVENT_TABLE()

        PaletteWindow::PaletteWindow(wxWindow* parent)
            : wxPanel(parent, wxID_ANY)
        {
        }

        void PaletteWindow::OnCloseWindow(wxCloseEvent& event)
        {
            Show(false);
            event.Veto();
        }
    }
}
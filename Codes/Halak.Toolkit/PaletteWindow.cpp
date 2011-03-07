#include <Halak.wxToolkit/PaletteWindow.h>

namespace Halak
{
    namespace wxToolkit
    {
        BEGIN_EVENT_TABLE(PaletteWindow, wxPanel)
            EVT_CLOSE(PaletteWindow::OnCloseWindow)
        END_EVENT_TABLE()

        PaletteWindow::PaletteWindow(wxWindow* parent, ServiceTree* services)
            : wxPanel(parent, wxID_ANY),
              services(services)
        {
        }

        void PaletteWindow::OnCloseWindow(wxCloseEvent& event)
        {
            Show(false);
            event.Veto();
        }
    }
}
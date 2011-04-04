#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/wxWidgetsWindow.h>

namespace Halak
{
    namespace Toolkit
    {
        wxWidgetsWindow::wxWidgetsWindow(wxWindow* window)
            : window(window)
        {
        }

        wxWidgetsWindow::~wxWidgetsWindow()
        {
        }

        void wxWidgetsWindow::Close()
        {
            window->Close();
        }

        Point wxWidgetsWindow::GetPosition() const
        {
            const wxPoint position = window->GetPosition();
            return Point(position.x, position.y);
        }

        void wxWidgetsWindow::SetPosition(Point value)
        {
            window->SetPosition(wxPoint(value.X, value.Y));
        }

        Point wxWidgetsWindow::GetSize() const
        {
            const wxSize size = window->GetClientSize();
            return Point(size.x, size.y);
        }

        void wxWidgetsWindow::SetSize(Point value)
        {
            window->SetClientSize(value.X, value.Y);
        }

        bool wxWidgetsWindow::GetVisible() const
        {
            return window->IsShown();
        }

        void wxWidgetsWindow::SetVisible(bool value)
        {
            window->Show(value);
        }

        void* wxWidgetsWindow::GetHandle() const
        {
            return window->GetHandle();
        }
    }
}
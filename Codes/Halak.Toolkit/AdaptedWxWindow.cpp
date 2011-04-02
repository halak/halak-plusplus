#include <Halak.Toolkit/AdaptedWxWindow.h>

namespace Halak
{
    namespace Toolkit
    {
        AdaptedWxWindow::AdaptedWxWindow(wxWindow* window)
            : window(window)
        {
        }

        AdaptedWxWindow::~AdaptedWxWindow()
        {
        }

        void AdaptedWxWindow::Close()
        {
            window->Close();
        }

        Point AdaptedWxWindow::GetPosition() const
        {
            const wxPoint position = window->GetPosition();
            return Point(position.x, position.y);
        }

        void AdaptedWxWindow::SetPosition(Point value)
        {
            window->SetPosition(wxPoint(value.X, value.Y));
        }

        Point AdaptedWxWindow::GetSize() const
        {
            const wxSize size = window->GetClientSize();
            return Point(size.x, size.y);
        }

        void AdaptedWxWindow::SetSize(Point value)
        {
            window->SetClientSize(value.X, value.Y);
        }

        bool AdaptedWxWindow::GetVisible() const
        {
            return window->IsShown();
        }

        void AdaptedWxWindow::SetVisible(bool value)
        {
            window->Show(value);
        }

        void* AdaptedWxWindow::GetHandle() const
        {
            return window->GetHandle();
        }
    }
}
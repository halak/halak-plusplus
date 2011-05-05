#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/Window.h>

namespace Halak
{
    namespace wxWidgets
    {
        Window::Window(wxWindow* window)
            : window(window)
        {
        }

        Window::~Window()
        {
        }

        void Window::Close()
        {
            window->Close();
        }

        Point Window::GetPosition() const
        {
            const wxPoint position = window->GetPosition();
            return Point(position.x, position.y);
        }

        void Window::SetPosition(Point value)
        {
            window->SetPosition(wxPoint(value.X, value.Y));
        }

        Point Window::GetSize() const
        {
            const wxSize size = window->GetClientSize();
            return Point(size.x, size.y);
        }

        void Window::SetSize(Point value)
        {
            window->SetClientSize(value.X, value.Y);
        }

        bool Window::GetVisible() const
        {
            return window->IsShown();
        }

        void Window::SetVisible(bool value)
        {
            window->Show(value);
        }

        void* Window::GetHandle() const
        {
            return window->GetHandle();
        }
    }
}
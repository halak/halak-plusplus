#include <Halak.wxToolkit/RenderPanel.h>
#include <Halak/DisplaySwapChain.h>
#include <Halak/Rectangle.h>

namespace Halak
{
    namespace wxToolkit
    {
        BEGIN_EVENT_TABLE(RenderPanel, wxPanel)
            EVT_ERASE_BACKGROUND(RenderPanel::OnDraw)
            EVT_TIMER(wxID_ANY, RenderPanel::OnIdle)
            EVT_SIZE(RenderPanel::OnSize)
            EVT_SCROLLWIN(RenderPanel::OnScrollWin)
        END_EVENT_TABLE()

        RenderPanel::RenderPanel(wxWindow* parent)
            : wxPanel(parent),
              swapChain(nullptr),
              idleTimer(this)
        {
            idleTimer.Start();
        }

        RenderPanel::~RenderPanel()
        {
        }

        DisplaySwapChain* RenderPanel::GetSwapChain() const
        {
            return swapChain;
        }

        void RenderPanel::SetSwapChain(DisplaySwapChain* value)
        {
            swapChain = value;
        }

        void RenderPanel::OnIdle(wxTimerEvent& /*event*/)
        {
            if (swapChain)
                Refresh();
        }

        void RenderPanel::OnDraw(wxEraseEvent& /*event*/)
        {
            if (swapChain)
            {
                const wxPoint scrollPosition(GetScrollPos(wxHORIZONTAL), GetScrollPos(wxVERTICAL));
                const wxSize size = GetClientSize();

                swapChain->SetViewport(Rectangle(scrollPosition.x, scrollPosition.y, size.x, size.y));

                swapChain->BeginDraw();
                Draw();
                swapChain->EndDraw();
                swapChain->Present();
            }
        }

        void RenderPanel::OnSize(wxSizeEvent& event)
        {
            if (swapChain)
            {
                SetScrollbar(wxHORIZONTAL, 0, event.GetSize().x, swapChain->GetBackbufferSize().X, false);
                SetScrollbar(wxVERTICAL,   0, event.GetSize().y, swapChain->GetBackbufferSize().Y, false);
            }
            else
            {
                SetScrollbar(wxHORIZONTAL, 0, 0, 0, false);
                SetScrollbar(wxVERTICAL,   0, 0, 0, false);
            }
        }

        void RenderPanel::OnScrollWin(wxScrollWinEvent& event)
        {
            int scrollPosition = 0;

            const wxEventType eventType = event.GetEventType();
            if (eventType == wxEVT_SCROLLWIN_TOP ||
                eventType == wxEVT_SCROLLWIN_BOTTOM ||
                eventType == wxEVT_SCROLLWIN_THUMBTRACK ||
                eventType == wxEVT_SCROLLWIN_THUMBRELEASE)
            {
                scrollPosition = event.GetPosition();
            }
            else if (eventType == wxEVT_SCROLLWIN_LINEUP ||
                     eventType == wxEVT_SCROLLWIN_LINEDOWN ||
                     eventType == wxEVT_SCROLLWIN_PAGEUP ||
                     eventType == wxEVT_SCROLLWIN_PAGEDOWN)
            {
                int offset = 0;
                if (eventType == wxEVT_SCROLLWIN_LINEUP)
                    offset = -1;
                else if (eventType == wxEVT_SCROLLWIN_LINEDOWN)
                    offset = +1;
                else if (eventType == wxEVT_SCROLLWIN_PAGEUP)
                    offset = -GetScrollThumb(event.GetOrientation()) / 10;
                else if (eventType == wxEVT_SCROLLWIN_PAGEDOWN)
                    offset = +GetScrollThumb(event.GetOrientation()) / 10;

                scrollPosition = GetScrollPos(event.GetOrientation()) + offset;
            }

            SetScrollPos(event.GetOrientation(), scrollPosition);
        }

        void RenderPanel::Draw()
        {
        }
    }
}
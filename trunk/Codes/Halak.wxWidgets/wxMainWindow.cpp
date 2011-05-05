#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/wxMainWindow.h>
#include <Halak.wxWidgets/wxHistoryWindow.h>
#include <Halak.wxWidgets/wxPaletteWindow.h>
#include <Halak.wxWidgets/wxPropertiesWindow.h>
#include <Halak.wxWidgets/wxUILayoutRenderPanel.h>
#include <Halak/CommandHistory.h>

namespace Halak
{
    namespace wxWidgets
    {
        enum IDs
        {
            MenuEditUndoID = 1,
            MenuEditRedoID,
        };

        BEGIN_EVENT_TABLE(wxMainWindow, wxFrame)
            EVT_ERASE_BACKGROUND(wxMainWindow::OnEraseBackground)
            EVT_SIZE(wxMainWindow::OnSize)

            EVT_MENU(MenuEditUndoID, wxMainWindow::OnMenuEditUndo)
            EVT_MENU(MenuEditRedoID, wxMainWindow::OnMenuEditRedo)
        END_EVENT_TABLE()

        wxMainWindow::wxMainWindow(const wxString& title, wxSize size, GameStructure* structure)
            : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER),
              structure(structure),
              notebook(notebook),
              layoutSuspended(false),
              history(nullptr)
        {
            auiManager.SetManagedWindow(this);
            SuspendLayout();
            //propertiesWindow = new PropertiesWindow(this, services);
            //propertiesWindow->SetClientSize(100, 100);
            //auiManager.AddPane(propertiesWindow, wxAuiPaneInfo()
            //                   .Name("Properties")
            //                   .Caption("Properties")
            //                   .Left()
            //                   .Layer(1)
            //                   .Position(1)
            //                   .CloseButton(true)
            //                   .MaximizeButton(true));

            //propertiesWindow = new PropertiesWindow(this, services);
            //propertiesWindow->SetClientSize(100, 100);
            //auiManager.AddPane(propertiesWindow, wxAuiPaneInfo()
            //                   .Name("Properties2")
            //                   .Caption("Properties2")
            //                   .Left()
            //                   .Layer(1)
            //                   .Position(2)
            //                   .CloseButton(true)
            //                   .MaximizeButton(true));

            notebook = new wxAuiNotebook(this, wxID_ANY, wxPoint(0, 0), wxSize(200, 200), wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER);
            auiManager.AddPane(notebook, wxAuiPaneInfo()
                               .Name("Notebook")
                               .CenterPane()
                               .PaneBorder(false));

            wxMenuBar* menuBar = new wxMenuBar();
            menuBar->SetThemeEnabled(true);
            SetupMenuBar(menuBar);
            SetMenuBar(menuBar);

            ResumeLayout();
            UpdateAcceleratorTable();
        }

        wxMainWindow::~wxMainWindow()
        {
            auiManager.UnInit();
        }

        void wxMainWindow::AddDockablePane(wxWindow* window, wxAuiPaneInfo& paneInfo)
        {
            auiManager.AddPane(window, paneInfo);
            if (layoutSuspended == false)
                auiManager.Update();
        }

        void wxMainWindow::AddNotebookPage(wxWindow* window, const String& caption)
        {
            notebook->AddPage(window, wxString(caption.CStr(), caption.GetLength()));
            if (layoutSuspended == false)
                auiManager.Update();
        }

        int wxMainWindow::GetNumberOfNotebookPages() const
        {
            return static_cast<int>(notebook->GetPageCount());
        }

        wxWindow* wxMainWindow::GetNotebookPage(int index)
        {
            return notebook->GetPage(index);
        }

        void wxMainWindow::SuspendLayout()
        {
            layoutSuspended = true;
        }

        void wxMainWindow::ResumeLayout()
        {
            layoutSuspended = false;
            auiManager.Update();
        }

        void wxMainWindow::UpdateMenuBar()
        {
            SetupMenuBar(GetMenuBar());
        }

        void wxMainWindow::UpdateAcceleratorTable()
        {
            std::vector<wxAcceleratorEntry> entries;
            SetupAcceleratorTable(entries);

            SetAcceleratorTable(wxAcceleratorTable(static_cast<int>(entries.size()), &entries[0]));
        }

        CommandHistory* wxMainWindow::GetHistory() const
        {
            return history;
        }

        void wxMainWindow::SetHistory(CommandHistory* value)
        {
            history = value;
        }

        void wxMainWindow::SetupMenuBar(wxMenuBar* menuBar)
        {
            wxMenu* menuFile = new wxMenu();
            menuFile->AppendSeparator();

            wxMenu* menuEdit = new wxMenu();
            menuEdit->Append(MenuEditUndoID, _("&Undo"));
            menuEdit->Append(MenuEditRedoID, _("&Redo"));
            menuEdit->AppendSeparator();

            menuBar->Append(menuFile, _("&File"));
            menuBar->Append(menuEdit, _("&Edit"));
        }

        void wxMainWindow::SetupAcceleratorTable(std::vector<wxAcceleratorEntry>& entries)
        {
            entries.reserve(entries.size() + 10);
            entries.push_back(wxAcceleratorEntry(wxACCEL_CTRL, 'Z', MenuEditUndoID));
            entries.push_back(wxAcceleratorEntry(wxACCEL_CTRL, 'Y', MenuEditRedoID));
        }

        void wxMainWindow::OnEraseBackground(wxEraseEvent& event)
        {
            event.Skip();
        }

        void wxMainWindow::OnSize(wxSizeEvent& event)
        {
            event.Skip();
        }

        void wxMainWindow::OnMenuEditUndo(wxCommandEvent& /*event*/)
        {
            if (history)
                history->Undo();
        }

        void wxMainWindow::OnMenuEditRedo(wxCommandEvent& /*event*/)
        {
            if (history)
                history->Redo();
        }
    }
}
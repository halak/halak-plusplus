#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/MainWindow.h>
#include <Halak.Toolkit/EntityRenderPanel.h>
#include <Halak.Toolkit/HistoryWindow.h>
#include <Halak.Toolkit/PaletteWindow.h>
#include <Halak.Toolkit/PropertiesWindow.h>
#include <Halak/CommandHistory.h>

namespace Halak
{
    namespace Toolkit
    {
        enum IDs
        {
            MenuEditUndoID = 1,
            MenuEditRedoID,
        };

        BEGIN_EVENT_TABLE(MainWindow, wxFrame)
            EVT_ERASE_BACKGROUND(MainWindow::OnEraseBackground)
            EVT_SIZE(MainWindow::OnSize)

            EVT_MENU(MenuEditUndoID, MainWindow::OnMenuEditUndo)
            EVT_MENU(MenuEditRedoID, MainWindow::OnMenuEditRedo)
        END_EVENT_TABLE()

        MainWindow::MainWindow(const wxString& title, wxSize size, GameStructure* structure)
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

        MainWindow::~MainWindow()
        {
            auiManager.UnInit();
        }

        void MainWindow::AddDockablePane(wxWindow* window, wxAuiPaneInfo& paneInfo)
        {
            auiManager.AddPane(window, paneInfo);
            if (layoutSuspended == false)
                auiManager.Update();
        }

        void MainWindow::AddNotebookPage(wxWindow* window, const wxString& caption)
        {
            notebook->AddPage(window, caption);
            if (layoutSuspended == false)
                auiManager.Update();
        }

        void MainWindow::AddNotebookPage(wxWindow* window, const String& caption)
        {
            AddNotebookPage(window, wxString(caption.CStr(), caption.GetLength()));
        }

        int MainWindow::GetNumberOfNotebookPages() const
        {
            return static_cast<int>(notebook->GetPageCount());
        }

        wxWindow* MainWindow::GetNotebookPage(int index)
        {
            return notebook->GetPage(index);
        }

        void MainWindow::SuspendLayout()
        {
            layoutSuspended = true;
        }

        void MainWindow::ResumeLayout()
        {
            layoutSuspended = false;
            auiManager.Update();
        }

        void MainWindow::UpdateMenuBar()
        {
            SetupMenuBar(GetMenuBar());
        }

        void MainWindow::UpdateAcceleratorTable()
        {
            std::vector<wxAcceleratorEntry> entries;
            SetupAcceleratorTable(entries);

            SetAcceleratorTable(wxAcceleratorTable(static_cast<int>(entries.size()), &entries[0]));
        }

        CommandHistory* MainWindow::GetHistory() const
        {
            return history;
        }

        void MainWindow::SetHistory(CommandHistory* value)
        {
            history = value;
        }

        void MainWindow::SetupMenuBar(wxMenuBar* menuBar)
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

        void MainWindow::SetupAcceleratorTable(std::vector<wxAcceleratorEntry>& entries)
        {
            entries.reserve(entries.size() + 10);
            entries.push_back(wxAcceleratorEntry(wxACCEL_CTRL, 'Z', MenuEditUndoID));
            entries.push_back(wxAcceleratorEntry(wxACCEL_CTRL, 'Y', MenuEditRedoID));
        }

        void MainWindow::OnEraseBackground(wxEraseEvent& event)
        {
            event.Skip();
        }

        void MainWindow::OnSize(wxSizeEvent& event)
        {
            event.Skip();
        }

        void MainWindow::OnMenuEditUndo(wxCommandEvent& /*event*/)
        {
            if (history)
                history->Undo();
        }

        void MainWindow::OnMenuEditRedo(wxCommandEvent& /*event*/)
        {
            if (history)
                history->Redo();
        }
    }
}
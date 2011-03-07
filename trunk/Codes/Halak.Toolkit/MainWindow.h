#pragma once
#ifndef __HALAK_WXTOOLKIT_MAINWINDOW_H__
#define __HALAK_WXTOOLKIT_MAINWINDOW_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <wx/wx.h>
#   include <wx/aui/aui.h>
#   include <vector>

    namespace Halak
    {
        namespace wxToolkit
        {
            class MainWindow : public wxFrame
            {
                public:
                    MainWindow(const wxString& title, wxSize size, ServiceTree* services);
                    virtual ~MainWindow();

                    void AddDockablePane(wxWindow* window, wxAuiPaneInfo& paneInfo);
                    void AddNotebookPage(wxWindow* window, const wxString& caption);
                    void AddNotebookPage(wxWindow* window, const String& caption);

                    int GetNumberOfNotebookPages() const;
                    wxWindow* GetNotebookPage(int index);

                    void SuspendLayout();
                    void ResumeLayout();

                    void UpdateMenuBar();
                    void UpdateAcceleratorTable();

                public:
                    CommandHistory* GetHistory() const;
                    void SetHistory(CommandHistory* value);

                protected:
                    virtual void SetupMenuBar(wxMenuBar* menuBar);
                    virtual void SetupAcceleratorTable(std::vector<wxAcceleratorEntry>& entries);

                private:
                    void OnEraseBackground(wxEraseEvent& event);
                    void OnSize(wxSizeEvent& event);

                    virtual void OnMenuEditUndo(wxCommandEvent& event);
                    virtual void OnMenuEditRedo(wxCommandEvent& event);

                private:
                    wxAuiManager   auiManager;
                    wxAuiNotebook* notebook;
                    ServiceTree*   services;
                    bool layoutSuspended;

                    CommandHistory* history;

                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
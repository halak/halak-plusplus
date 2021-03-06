#pragma once
#ifndef __HALAK_WXWIDGETS_WXMAINWINDOW_H__
#define __HALAK_WXWIDGETS_WXMAINWINDOW_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <wx/wx.h>
#   include <wx/aui/aui.h>
#   include <vector>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxMainWindow : public wxFrame
            {
                public:
                    wxMainWindow(const wxString& title, wxSize size, GameStructure* structure);
                    virtual ~wxMainWindow();

                    void AddDockablePane(wxWindow* window, wxAuiPaneInfo& paneInfo);
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
                    GameStructure* structure;
                    bool layoutSuspended;

                    CommandHistory* history;

                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
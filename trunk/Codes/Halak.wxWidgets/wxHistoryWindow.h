#pragma once
#ifndef __HALAK_WXWIDGETS_HISTORYWINDOW_H__
#define __HALAK_WXWIDGETS_HISTORYWINDOW_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <wx/wx.h>
#   include <wx/treectrl.h>
#   include <list>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxHistoryWindow : public wxPanel
            {
                public:
                    wxHistoryWindow(wxWindow* parent);
                    virtual ~wxHistoryWindow();

                    CommandHistory* GetHistory() const;
                    void SetHistory(CommandHistory* value);

                protected:
                    void OnItemSelected(wxTreeEvent& event);

                    virtual void OnCommandExecuted(CommandHistory* sender, Command* command, const std::list<Command*>& /*cancelledCommands*/);
                    virtual void OnCommandUndone(CommandHistory* sender, const std::list<Command*>& commands);
                    virtual void OnCommandRedone(CommandHistory* sender, const std::list<Command*>& commands);

                private:
                    struct Fields;
                    Fields* mPointer;
                    Fields& m;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif
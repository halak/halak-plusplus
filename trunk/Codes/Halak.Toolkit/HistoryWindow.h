#pragma once
#ifndef __HALAK_TOOLKIT_HISTORYWINDOW_H__
#define __HALAK_TOOLKIT_HISTORYWINDOW_H__

#   include <Halak.Toolkit/FWD.h>
#   include <wx/wx.h>
#   include <wx/treectrl.h>
#   include <list>

    namespace Halak
    {
        namespace Toolkit
        {
            class HistoryWindow : public wxPanel
            {
                public:
                    HistoryWindow(wxWindow* parent);
                    virtual ~HistoryWindow();

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
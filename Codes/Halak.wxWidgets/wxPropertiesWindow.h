#pragma once
#ifndef __HALAK_WXWIDGETS_PROPERTIESWINDOW_H__
#define __HALAK_WXWIDGETS_PROPERTIESWINDOW_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <Halak.Toolkit/AnyPtr.h>
#   include <wx/wx.h>
#   include <wx/propgrid/propgrid.h>
#   include <list>
#   include <vector>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxPropertiesWindow : public wxPanel
            {
                public:
                    typedef std::vector<Halak::Toolkit::AnyPtr> AnyPtrCollection;

                public:
                    wxPropertiesWindow(wxWindow* parent);
                    virtual ~wxPropertiesWindow();

                    void UpdateProperties();

                    CommandHistory* GetHistory() const;
                    void SetHistory(CommandHistory* value);

                    const Halak::Toolkit::AnyPtr& GetTargetPointee() const;
                    void SetTarget(const Halak::Toolkit::AnyPtr& value);

                    const AnyPtrCollection& GetTargets() const;
                    void SetTargets(const AnyPtrCollection& value);

                protected:
                    void OnPropertyGridSelected(wxPropertyGridEvent& event);
                    void OnPropertyGridChanged(wxPropertyGridEvent& event);
                    void OnPropertyGridChanging(wxPropertyGridEvent& event);
                    void OnPropertyGridHighlighted(wxPropertyGridEvent& event);
                    void OnPropertyGridItemCollapsed(wxPropertyGridEvent& event);
                    void OnPropertyGridItemExpanded(wxPropertyGridEvent& event);

                    virtual void OnCommandExecuted(CommandHistory* sender, Command* command, const std::list<Command*>& /*cancelledCommands*/);
                    virtual void OnCommandUndone(CommandHistory* sender, const std::list<Command*>& commands);
                    virtual void OnCommandRedone(CommandHistory* sender, const std::list<Command*>& commands);

                private:
                    void FillPage(const Halak::Toolkit::ClassInfo* classInfo);

                private:
                    CommandHistory* history;
                    AnyPtrCollection targets;
                    
                    wxPropertyGridManager* propertyGridManager;
                    wxPropertyGrid*        propertyGrid;

                    wxWindow*   panel;
                    wxBoxSizer* topSizer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#   include <Halak.wxWidgets/wxPropertiesWindow.inl>

#endif
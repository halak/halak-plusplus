#pragma once
#ifndef __HALAK_WXTOOLKIT_PROPERTIESWINDOW_H__
#define __HALAK_WXTOOLKIT_PROPERTIESWINDOW_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Any.h>
#   include <wx/wx.h>
#   include <wx/propgrid/propgrid.h>
#   include <list>

    namespace Halak
    {
        namespace wxToolkit
        {
            class PropertiesWindow : public wxPanel
            {
                public:
                    typedef std::vector<AnyPtr> AnyPtrCollection;

                public:
                    PropertiesWindow(wxWindow* parent);
                    virtual ~PropertiesWindow();

                    void UpdateProperties();

                    CommandHistory* GetHistory() const;
                    void SetHistory(CommandHistory* value);

                    const Halak::AnyPtr& GetTargetPointee() const;
                    void SetTarget(const Halak::AnyPtr& value);

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
                    void FillPage(const Halak::ClassInfo* classInfo);

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

#   include <Halak.wxToolkit/PropertiesWindow.inl>

#endif
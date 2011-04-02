#include <Halak.Toolkit/PropertiesWindow.h>
#include <Halak.Toolkit/IPropertyUpdateable.h>
#include <Halak.Toolkit/NumberProperty.h>
#include <Halak.Toolkit/Vector3Property.h>
#include <Halak.Toolkit/Attributes.h>
#include <Halak.Toolkit/ClassInfo.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak/CommandHistory.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/propdev.h>
#include <wx/propgrid/advprops.h>

namespace Halak
{
    namespace Toolkit
    {
        enum IDs
        {
            PropertyGridID = 100,
        };

        BEGIN_EVENT_TABLE(PropertiesWindow, wxPanel)
            EVT_PG_SELECTED      (PropertyGridID, PropertiesWindow::OnPropertyGridSelected)
            EVT_PG_CHANGED       (PropertyGridID, PropertiesWindow::OnPropertyGridChanged)
            EVT_PG_CHANGING      (PropertyGridID, PropertiesWindow::OnPropertyGridChanging)
            EVT_PG_HIGHLIGHTED   (PropertyGridID, PropertiesWindow::OnPropertyGridHighlighted)
            EVT_PG_ITEM_COLLAPSED(PropertyGridID, PropertiesWindow::OnPropertyGridItemCollapsed)
            EVT_PG_ITEM_EXPANDED (PropertyGridID, PropertiesWindow::OnPropertyGridItemExpanded)
        END_EVENT_TABLE()

        PropertiesWindow::PropertiesWindow(wxWindow* parent)
            : wxPanel(parent, wxID_ANY),
              history(nullptr),
              propertyGridManager(nullptr),
              propertyGrid(nullptr),
              panel(nullptr),
              topSizer(nullptr)
        {
            const int style = wxPG_BOLD_MODIFIED |
                              wxPG_SPLITTER_AUTO_CENTER |
                              wxPG_AUTO_SORT /*|
                              wxPG_TOOLTIPS*/ |
                              wxPG_TOOLBAR |
                              wxPG_DESCRIPTION;
            const int exStyle = wxPG_EX_MODE_BUTTONS |
                                wxPG_EX_ENABLE_TLP_TRACKING |
                                wxPG_EX_UNFOCUS_ON_ENTER |
                                wxPG_EX_MULTIPLE_SELECTION /*|
                                wxPG_EX_GREY_LABEL_WHEN_DISABLED*/;

            panel    = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(100, 100));
            topSizer = new wxBoxSizer(wxVERTICAL);

            propertyGridManager = new wxPropertyGridManager(panel, PropertyGridID,
                                                            wxDefaultPosition, wxDefaultSize,
                                                            style);
            propertyGridManager->SetExtraStyle(exStyle);
            propertyGridManager->SetValidationFailureBehavior(wxPG_VFB_BEEP | wxPG_VFB_MARK_CELL | wxPG_VFB_SHOW_MESSAGE);

            propertyGrid = propertyGridManager->GetGrid();
            propertyGrid->SetVerticalSpacing(2);
            propertyGrid->SetUnspecifiedValueAppearance(wxPGCell("Unspecified", wxNullBitmap, *wxLIGHT_GREY));

            topSizer->Add(propertyGridManager, 1, wxEXPAND);

            panel->SetSizer(topSizer);
            topSizer->SetSizeHints(panel);

            wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
            panelSizer->Add(panel, 1, wxEXPAND | wxFIXED_MINSIZE);
            SetSizer(panelSizer);
            panelSizer->SetSizeHints(this);

            wxPropertyGridManager::RegisterAdditionalEditors();
        }

        PropertiesWindow::~PropertiesWindow()
        {
            SetHistory(nullptr); // disconnect slots
        }

        void PropertiesWindow::UpdateProperties()
        {
            wxPropertyGridPage* page = propertyGridManager->GetPage(0);
            for (wxPropertyGridIterator it = page->GetIterator(); it.AtEnd() == false; it++)
            {
                if (IPropertyUpdateable* updateable = dynamic_cast<IPropertyUpdateable*>(*it))
                    updateable->UpdateFrom(targets);
            }
        }

        CommandHistory* PropertiesWindow::GetHistory() const
        {
            return history;
        }

        void PropertiesWindow::SetHistory(CommandHistory* value)
        {
            if (history != value)
            {
                if (history)
                {
                    history->Redone().Disconnect(this, &PropertiesWindow::OnCommandRedone);
                    history->Undone().Disconnect(this, &PropertiesWindow::OnCommandUndone);
                    history->Executed().Disconnect(this, &PropertiesWindow::OnCommandExecuted);
                }

                history = value;

                if (history)
                {
                    history->Executed().Connect(this, &PropertiesWindow::OnCommandExecuted);
                    history->Undone().Connect(this, &PropertiesWindow::OnCommandUndone);
                    history->Redone().Connect(this, &PropertiesWindow::OnCommandRedone);
                }
            }
        }

        const AnyPtr& PropertiesWindow::GetTargetPointee() const
        {
            if (targets.empty() == false)
                return targets.front();
            else
                return AnyPtr::Null;
        }

        void PropertiesWindow::SetTarget(const AnyPtr& value)
        {
            if (value.GetPointeeType()->IsClass())
            {
                targets.clear();
                targets.push_back(value);
                FillPage(static_cast<const ClassInfo*>(value.GetPointeeType()));
            }
        }

        const PropertiesWindow::AnyPtrCollection& PropertiesWindow::GetTargets() const
        {
            return targets;
        }

        void PropertiesWindow::SetTargets(const AnyPtrCollection& value)
        {
            targets = value;
            //FillPage(TypeLibrary::GetInstance().GetTypeInfo<T::element_type>());
        }
    
        void PropertiesWindow::OnPropertyGridSelected(wxPropertyGridEvent& event)
        {
        }

        void PropertiesWindow::OnPropertyGridChanged(wxPropertyGridEvent& event)
        {
            if (IPropertyUpdateable* updateable = dynamic_cast<IPropertyUpdateable*>(event.GetProperty()))
                updateable->UpdateTo(targets);
        }

        void PropertiesWindow::OnPropertyGridChanging(wxPropertyGridEvent& event)
        {
        }

        void PropertiesWindow::OnPropertyGridHighlighted(wxPropertyGridEvent& event)
        {
        }

        void PropertiesWindow::OnPropertyGridItemCollapsed(wxPropertyGridEvent& event)
        {
        }

        void PropertiesWindow::OnPropertyGridItemExpanded(wxPropertyGridEvent& event)
        {
        }
            
        void PropertiesWindow::OnCommandExecuted(CommandHistory* sender, Command* /*command*/, const std::list<Command*>& /*cancelledCommands*/)
        {
            HKAssert(history == sender);
            UpdateProperties();
        }

        void PropertiesWindow::OnCommandUndone(CommandHistory* sender, const std::list<Command*>& /*commands*/)
        {
            HKAssert(history == sender);
            UpdateProperties();
        }

        void PropertiesWindow::OnCommandRedone(CommandHistory* sender, const std::list<Command*>& /*commands*/)
        {
            HKAssert(history == sender);
            UpdateProperties();
        }

        void PropertiesWindow::FillPage(const ClassInfo* classInfo)
        {
            const int numberOfPages = propertyGridManager->GetPageCount();
            for (int i = numberOfPages - 1; i >= 0; i--)
                propertyGridManager->RemovePage(i);

            int index = propertyGridManager->AddPage(classInfo->GetName());
            wxPropertyGridPage* propertyGridPage = propertyGridManager->GetPage(index);

            const ClassInfo::PropertyCollection& properties = classInfo->GetProperties();

            for (ClassInfo::PropertyCollection::const_iterator it = properties.begin(); it != properties.end(); it++)
            {
                wxPGProperty* newProperty = nullptr;
                if (String((*it)->GetName()) == "LinearVelocity1" || String((*it)->GetName()) == "LinearVelocity2")
                {
                    newProperty = new Vector3Property((*it)->GetName(), wxPG_LABEL, history, (*it));
                }
                else if (String((*it)->GetName()) == "Lifespan1" || String((*it)->GetName()) == "Lifespan2")
                {
                    newProperty = new NumberProperty((*it)->GetName(), wxPG_LABEL, history, (*it));
                }
                else
                {
                    newProperty = new wxIntProperty((*it)->GetName(), wxPG_LABEL, 0);
                }

                if (const UnitAttribute* attribute = (*it)->FindAttribute<UnitAttribute>())
                    newProperty->SetAttribute(wxPG_ATTR_UNITS, attribute->GetName());

                newProperty->SetClientData((void*)(*it));
                propertyGridPage->Append(newProperty);
            }

            UpdateProperties();
        }
    }
}
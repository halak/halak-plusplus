#include <Halak.wxToolkit/EntityTreeWindow.h>
#include <Halak.wxToolkit/BaseApplication.h>
#include <Halak.wxToolkit/DocumentFolder.h>
#include <Halak.wxToolkit/EntityDocument.h>
#include <Halak.wxToolkit/EntityRenderPanel.h>
#include <Halak.wxToolkit/MainWindow.h>
#include <Halak/Any.h>
#include <Halak/ClassInfo.h>
#include <Halak/RootEntity.h>
#include <Halak/TypeLibrary.h>
#include <wx/treectrl.h>
#include <algorithm>

namespace Halak
{
    namespace wxToolkit
    {
        enum IDs
        {
            EntityTreeID = 300,

            MenuOpenRenderPanelID,
            MenuOpenDesignPanelID,
        };

        struct EntityTreeWindow::Fields
        {
            ServiceTree* services;
            RootEntityCollection entities;
            DocumentFolder* documentFolder;
            wxTreeCtrl* tree;

            Fields(ServiceTree* services)
                : services(services),
                  tree(nullptr),
                  documentFolder(nullptr)
            {
            }

            void RebuildItems();
            void UpdateItem(const wxTreeItemId& id);
            void AppendItem(const wxTreeItemId& parentID, EntityPtr entity);
            wxTreeItemId FindItem(RootEntityPtr entity) const;
        };

        class EntityTreeItemData : public wxTreeItemData
        {
            public:
                EntityTreeItemData(const Any& value)
                    : value(value)
                {
                }

                const Any& GetValue() const { return value; }

            private:
                Any value;
        };

        BEGIN_EVENT_TABLE(EntityTreeWindow, wxPanel)
            EVT_TREE_ITEM_MENU(EntityTreeID, EntityTreeWindow::OnItemMenu)

            EVT_MENU(MenuOpenRenderPanelID, EntityTreeWindow::OnMenuOpenRenderPanel)
            EVT_MENU(MenuOpenDesignPanelID, EntityTreeWindow::OnMenuOpenDesignPanel)
        END_EVENT_TABLE()

        EntityTreeWindow::EntityTreeWindow(wxWindow* parent, ServiceTree* services)
            : wxPanel(parent, wxID_ANY),
              mPointer(new Fields(services)),
              m(*mPointer)
        {
            m.tree = new wxTreeCtrl(this, EntityTreeID,
                                    wxPoint(0, 0), wxSize(100, 100),
                                    wxNO_BORDER | wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT | wxTR_HAS_VARIABLE_ROW_HEIGHT | wxTR_ROW_LINES | wxTR_HIDE_ROOT);
            wxTreeItemId root = m.tree->AddRoot("Entities", 0);
        }

        EntityTreeWindow::~EntityTreeWindow()
        {
            SetDocumentFolder(nullptr);
            delete mPointer;
        }

        //void EntityTreeWindow::AddEntity(RootEntityPtr item)
        //{
        //    if (std::find(m.entities.begin(), m.entities.end(), item) != m.entities.end())
        //        return;

        //    m.entities.push_back(item);
        //    
        //    wxTreeItemId rootID = m.tree->GetRootItem();
        //    m.tree->AppendItem(rootID, "Entity", -1, -1, new EntityTreeItemData(item));
        //}

        //void EntityTreeWindow::RemoveEntity(RootEntityPtr item)
        //{
        //    RootEntityCollection::iterator it = std::find(m.entities.begin(), m.entities.end(), item);
        //    if (it == m.entities.end())
        //        return;

        //    m.entities.erase(it);

        //    wxTreeItemIdValue cookie;
        //    wxTreeItemId rootID = m.tree->GetRootItem();
        //    for (wxTreeItemId id = m.tree->GetFirstChild(rootID, cookie); id.IsOk(); id = m.tree->GetNextChild(rootID, cookie))
        //    {
        //        if (EntityTreeItemData* userData = static_cast<EntityTreeItemData*>(m.tree->GetItemData(id)))
        //        {
        //            if (userData->GetValue() == Any(item))
        //            {
        //                m.tree->Delete(id);
        //                break;
        //            }
        //        }
        //    }
        //}

        //void EntityTreeWindow::ClearEntities()
        //{
        //    m.entities.clear();
        //}

        DocumentFolder* EntityTreeWindow::GetDocumentFolder() const
        {
            return m.documentFolder;
        }

        void EntityTreeWindow::SetDocumentFolder(DocumentFolder* value)
        {
            if (m.documentFolder != value)
            {
                if (m.documentFolder)
                {
                    m.documentFolder->Added().Disconnect(this, &EntityTreeWindow::OnDocumentAdded);
                    m.documentFolder->Removed().Disconnect(this, &EntityTreeWindow::OnDocumentRemoved);
                    m.documentFolder->Cleared().Disconnect(this, &EntityTreeWindow::OnDocumentsCleared);
                }

                m.documentFolder = value;

                if (m.documentFolder)
                {
                    m.documentFolder->Cleared().Connect(this, &EntityTreeWindow::OnDocumentsCleared);
                    m.documentFolder->Removed().Connect(this, &EntityTreeWindow::OnDocumentRemoved);
                    m.documentFolder->Added().Connect(this, &EntityTreeWindow::OnDocumentAdded);
                }

                m.RebuildItems();
            }
        }

        const EntityTreeWindow::RootEntityCollection& EntityTreeWindow::GetRootEntities() const
        {
            return m.entities;
        }

        EntityRenderPanel* EntityTreeWindow::FindEntityRenderPanel(RootEntityPtr entity)
        {
            MainWindow* mainWindow = BaseApplication::GetInstance()->GetMainWindow();
            const int count = mainWindow->GetNumberOfNotebookPages();
            for (int i = 0; i < count; i++)
            {
                EntityRenderPanel* item = dynamic_cast<EntityRenderPanel*>(mainWindow->GetNotebookPage(i));
                if (item && item->GetTargetPointee() == entity)
                    return item;
            }

            return nullptr;
        }

        void EntityTreeWindow::OnItemMenu(wxTreeEvent& event)
        {
            const wxPoint clientPosition = event.GetPoint();

            wxTreeItemId id = event.GetItem();
            if (id.IsOk())
            {
                wxMenu menu;
                menu.Append(MenuOpenRenderPanelID, _("Open &Render Panel"));
                menu.Append(MenuOpenDesignPanelID, _("Open &Design Panel"));
                PopupMenu(&menu, clientPosition);
            }

            event.Skip();
        }

        void EntityTreeWindow::OnMenuOpenRenderPanel(wxCommandEvent& /*event*/)
        {
            wxTreeItemId id = m.tree->GetSelection();
            if (id.IsOk())
            {
                const EntityTreeItemData* itemData = static_cast<const EntityTreeItemData*>(m.tree->GetItemData(id));
                RootEntityPtr entity = itemData->GetValue().CastTo<RootEntityPtr>();

                if (EntityRenderPanel* existingRenderPanel = FindEntityRenderPanel(entity))
                    existingRenderPanel->Show();
                else
                {
                    MainWindow* mainWindow = BaseApplication::GetInstance()->GetMainWindow();
                    EntityRenderPanel* renderPanel = new EntityRenderPanel(mainWindow, GetDocumentFolder()->Find(entity));
                    mainWindow->AddNotebookPage(renderPanel, entity->GetName());
                }
            }
        }

        void EntityTreeWindow::OnMenuOpenDesignPanel(wxCommandEvent& /*event*/)
        {
        }

        void EntityTreeWindow::OnDocumentAdded(DocumentFolder* sender, DocumentPtr document)
        {
            HKAssertDebug(sender == m.documentFolder);

            if (EntityDocumentPtr entityDocument = dynamic_pointer_cast<EntityDocument>(document))
            {
                RootEntityPtr entity = entityDocument->GetEntity();

                if (std::find(m.entities.begin(), m.entities.end(), entity) != m.entities.end())
                    return;

                m.entities.push_back(entity);
                m.AppendItem(m.tree->GetRootItem(), entity);
            }
        }

        void EntityTreeWindow::OnDocumentRemoved(DocumentFolder* sender, DocumentPtr document)
        {
            HKAssertDebug(sender == m.documentFolder);

            if (EntityDocumentPtr entityDocument = dynamic_pointer_cast<EntityDocument>(document))
            {
                RootEntityPtr entity = entityDocument->GetEntity();
                wxTreeItemId id = m.FindItem(entity);
                if (id.IsOk())
                {
                    m.tree->Delete(id);

                    RootEntityCollection::iterator it = std::find(m.entities.begin(), m.entities.end(), entity);
                    HKAssert(it != m.entities.end());
                    m.entities.erase(it);
                }
            }
        }

        void EntityTreeWindow::OnDocumentsCleared(DocumentFolder* sender, const std::list<DocumentPtr>& /*documents*/)
        {
            HKAssertDebug(sender == m.documentFolder);

            m.tree->DeleteChildren(m.tree->GetRootItem());
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        void EntityTreeWindow::Fields::RebuildItems()
        {
            const wxTreeItemId& rootID = tree->GetRootItem();
            tree->DeleteChildren(rootID);

            if (documentFolder == nullptr)
                return;

            const DocumentFolder::DocumentCollection& documents = documentFolder->GetDocuments();
            for (DocumentFolder::DocumentCollection::const_iterator it = documents.begin(); it != documents.end(); it++)
            {
                if (EntityDocumentPtr entityDocument = dynamic_pointer_cast<EntityDocument>(*it))
                    AppendItem(rootID, entityDocument->GetEntity());
            }
        }

        void EntityTreeWindow::Fields::UpdateItem(const wxTreeItemId& id)
        {
            const Any& itemData = static_cast<EntityTreeItemData*>(tree->GetItemData(id))->GetValue();
            EntityPtr entity = itemData.CastTo<EntityPtr>();

            const ClassInfo* classInfo = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo(entity.GetPointee()));
            tree->SetItemText(id, classInfo->GetName());
        }

        void EntityTreeWindow::Fields::AppendItem(const wxTreeItemId& parentID, EntityPtr entity)
        {
            wxTreeItemId id = tree->AppendItem(parentID, "", -1, -1, new EntityTreeItemData(entity));
            UpdateItem(id);
        }

        wxTreeItemId EntityTreeWindow::Fields::FindItem(RootEntityPtr entity) const
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId rootID = tree->GetRootItem();

            for (wxTreeItemId id = tree->GetFirstChild(rootID, cookie); id.IsOk(); id = tree->GetNextChild(rootID, cookie))
            {
                const Any& itemData = static_cast<EntityTreeItemData*>(tree->GetItemData(id))->GetValue();
                if (itemData.CastTo<EntityPtr>() == entity)
                    return id;
            }

            return wxTreeItemId();
        }
    }
}
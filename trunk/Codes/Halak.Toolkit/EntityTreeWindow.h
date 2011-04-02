#pragma once
#ifndef __HALAK_TOOLKIT_ENTITYTREEWINDOW_H__
#define __HALAK_TOOLKIT_ENTITYTREEWINDOW_H__

#   include <Halak.Toolkit/FWD.h>
#   include <wx/wx.h>
#   include <wx/treectrl.h>
#   include <list>

    namespace Halak
    {
        namespace Toolkit
        {
            class EntityTreeWindow : public wxPanel
            {
                public:
                    typedef std::list<RootEntityPtr> RootEntityCollection;

                public:
                    EntityTreeWindow(wxWindow* parent, ServiceTree* services);
                    virtual ~EntityTreeWindow();

                    //void AddEntity(RootEntityPtr item);
                    //void RemoveEntity(RootEntityPtr item);
                    //void ClearEntities();

                    DocumentFolder* GetDocumentFolder() const;
                    void SetDocumentFolder(DocumentFolder* value);

                    const RootEntityCollection& GetRootEntities() const;

                protected:
                    EntityRenderPanel* FindEntityRenderPanel(RootEntityPtr entity);

                    virtual void OnItemMenu(wxTreeEvent& event);
                    virtual void OnMenuOpenRenderPanel(wxCommandEvent& event);
                    virtual void OnMenuOpenDesignPanel(wxCommandEvent& event);

                    virtual void OnDocumentAdded(DocumentFolder* sender, DocumentPtr document);
                    virtual void OnDocumentRemoved(DocumentFolder* sender, DocumentPtr document);
                    virtual void OnDocumentsCleared(DocumentFolder* sender, const std::list<DocumentPtr>& documents);

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
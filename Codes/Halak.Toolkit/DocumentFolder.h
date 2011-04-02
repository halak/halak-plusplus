#pragma once
#ifndef __HALAK_TOOLKIT_DOCUMENTFOLDER_H__
#define __HALAK_TOOLKIT_DOCUMENTFOLDER_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Signal.h>
#   include <list>

    namespace Halak
    {
        namespace Toolkit
        {
            class DocumentFolder : public GameComponent
            {
                public:
                    typedef std::list<Document*> DocumentCollection;

                public:
                    DocumentFolder();
                    virtual ~DocumentFolder();

                    void Add(DocumentPtr item);
                    bool Remove(DocumentPtr item);
                    void Clear();

                    EntityDocumentPtr Find(RootEntityPtr entity) const;

                    const DocumentCollection& GetDocuments() const;

                    Signal<DocumentFolder*, DocumentPtr>& Added();
                    Signal<DocumentFolder*, DocumentPtr>& Removed();
                    Signal<DocumentFolder*, const DocumentCollection&>& Cleared();

                private:
                    DocumentCollection documents;

                    Signal<DocumentFolder*, DocumentPtr> added;
                    Signal<DocumentFolder*, DocumentPtr> removed;
                    Signal<DocumentFolder*, const DocumentCollection&> cleared;
            };
        }
    }

#endif
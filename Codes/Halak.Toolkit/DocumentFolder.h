#pragma once
#ifndef __HALAK_WXTOOLKIT_DOCUMENTFOLDER_H__
#define __HALAK_WXTOOLKIT_DOCUMENTFOLDER_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Service.h>
#   include <Halak/Signal.h>
#   include <list>

    namespace Halak
    {
        namespace wxToolkit
        {
            class DocumentFolder : public Service
            {
                public:
                    typedef std::list<DocumentPtr> DocumentCollection;

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
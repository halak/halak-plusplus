#include <Halak.Toolkit/DocumentFolder.h>
#include <Halak.Toolkit/Document.h>
#include <Halak.Toolkit/EntityDocument.h>
#include <Halak/Assert.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        DocumentFolder::DocumentFolder()
        {
        }

        DocumentFolder::~DocumentFolder()
        {
        }

        void DocumentFolder::Add(DocumentPtr item)
        {
            if (item == nullptr)
                throw std::invalid_argument("item is nullptr");

            HKAssert(std::find(documents.begin(), documents.end(), item) == documents.end());
            documents.push_back(item);

            added.Emit(this, item);
        }

        bool DocumentFolder::Remove(DocumentPtr item)
        {
            if (item == nullptr)
                return false;

            DocumentCollection::iterator it = std::find(documents.begin(), documents.end(), item);
            if (it != documents.end())
            {
                documents.erase(it);
                removed.Emit(this, item);
                return true;
            }
            else
                return false;
        }

        void DocumentFolder::Clear()
        {
            DocumentCollection removingDocuments;
            removingDocuments.swap(documents);

            cleared.Emit(this, removingDocuments);
        }

        EntityDocumentPtr DocumentFolder::Find(RootEntityPtr entity) const
        {
            for (DocumentCollection::const_iterator it = documents.begin(); it != documents.end(); it++)
            {
                EntityDocumentPtr item = dynamic_pointer_cast<EntityDocument>(*it);
                if (item && item->GetEntity() == entity)
                    return item;
            }

            return nullptr;
        }

        const DocumentFolder::DocumentCollection& DocumentFolder::GetDocuments() const
        {
            return documents;
        }

        Signal<DocumentFolder*, DocumentPtr>& DocumentFolder::Added()
        {
            return added;
        }

        Signal<DocumentFolder*, DocumentPtr>& DocumentFolder::Removed()
        {
            return removed;
        }

        Signal<DocumentFolder*, const DocumentFolder::DocumentCollection&>& DocumentFolder::Cleared()
        {
            return cleared;
        }
    }
}
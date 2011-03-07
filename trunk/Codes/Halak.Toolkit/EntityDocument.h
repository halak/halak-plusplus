#pragma once
#ifndef __HALAK_WXTOOLKIT_ENTITYDOCUMENT_H__
#define __HALAK_WXTOOLKIT_ENTITYDOCUMENT_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak.wxToolkit/Document.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class EntityDocument : public Document
            {
                public:
                    EntityDocument(RootEntityPtr entity, ServiceTree* services);
                    virtual ~EntityDocument();

                    RootEntityPtr GetEntity() const;

                    ServiceNode* GetLocalServices() const;
                    Timeline* GetTimeline() const;
                    CommandHistory* GetHistory() const;

                private:
                    RootEntityPtr entity;

                    ServiceTree* globalServices;
                    ServiceNode* localServices;
                    Timeline* timeline;
                    CommandHistory* history;
            };
        }
    }

#endif
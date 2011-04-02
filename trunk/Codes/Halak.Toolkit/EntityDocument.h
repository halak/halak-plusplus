#pragma once
#ifndef __HALAK_TOOLKIT_ENTITYDOCUMENT_H__
#define __HALAK_TOOLKIT_ENTITYDOCUMENT_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Document.h>

    namespace Halak
    {
        namespace Toolkit
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
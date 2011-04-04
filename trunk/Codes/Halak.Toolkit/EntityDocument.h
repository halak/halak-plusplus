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
                    EntityDocument(RootEntityPtr entity, GameStructure* structure);
                    virtual ~EntityDocument();

                    RootEntityPtr GetEntity() const;

                    Timeline* GetTimeline() const;
                    CommandHistory* GetHistory() const;

                private:
                    RootEntityPtr entity;

                    GameStructure* structure;
                    Timeline* timeline;
                    CommandHistory* history;
            };
        }
    }

#endif
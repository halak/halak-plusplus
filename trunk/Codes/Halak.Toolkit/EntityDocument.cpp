#include <Halak.Toolkit/EntityDocument.h>
#include <Halak/Assert.h>
#include <Halak/CommandHistory.h>
#include <Halak/GameStructure.h>
#include <Halak/GameNode.h>
#include <Halak/RootEntity.h>
#include <Halak/Timeline.h>

namespace Halak
{
    namespace Toolkit
    {
        EntityDocument::EntityDocument(RootEntityPtr entity, GameStructure* structure)
            : entity(entity),
              structure(structure),
              timeline(new Timeline()),
              history(new CommandHistory())
        {
            HKAssert(structure);
            //localServices = globalServices->GetRoot()->AttachChild(nullptr);
            //localServices->Add(history);
            //localServices->Add(timeline);
            //structure->Add(localServices);
        }

        EntityDocument::~EntityDocument()
        {
            /*structure->GetRoot()->DetachChild(localServices);*/
        }

        RootEntityPtr EntityDocument::GetEntity() const
        {
            return entity;
        }

        CommandHistory* EntityDocument::GetHistory() const
        {
            return history;
        }

        Timeline* EntityDocument::GetTimeline() const
        {
            return timeline;
        }
    }
}
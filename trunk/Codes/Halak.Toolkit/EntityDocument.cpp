#include <Halak.Toolkit/EntityDocument.h>
#include <Halak/Assert.h>
#include <Halak/CommandHistory.h>
#include <Halak/GameStructure.h>
#include <Halak/RootEntity.h>
#include <Halak/Timeline.h>

namespace Halak
{
    namespace Toolkit
    {
        EntityDocument::EntityDocument(RootEntityPtr entity, ServiceTree* services)
            : entity(entity),
              globalServices(services),
              localServices(nullptr),
              timeline(new Timeline()),
              history(new CommandHistory())
        {
            HKAssert(globalServices);
            localServices = globalServices->GetRoot()->AttachChild(nullptr);
            localServices->Add(history);
            localServices->Add(timeline);
            globalServices->Add(localServices);
        }

        EntityDocument::~EntityDocument()
        {
            globalServices->GetRoot()->DetachChild(localServices);
        }

        RootEntityPtr EntityDocument::GetEntity() const
        {
            return entity;
        }

        ServiceTree* EntityDocument::GetLocalServices() const
        {
            return localServices;
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
#include <Halak/GameStructure.h>
#include <Halak/Assert.h>
#include <Halak/GameComponent.h>
#include <Halak/GameNode.h>

namespace Halak
{
    GameStructure::GameStructure()
    {
        root = new GameNode(GameNode::NullComponentTag());
        root->structure = this;
    }

    GameStructure::~GameStructure()
    {
        root->structure = nullptr;
        delete root;
    }

    GameComponent* GameStructure::Find(uint32 id) const
    {
        if (GameNode* foundNode = FindNode(id))
            return foundNode->GetComponent();
        else
            return nullptr;
    }

    GameNode* GameStructure::FindNode(uint32 id) const
    {
        UIntNodeDictionary::const_iterator it = idNodes.find(id);
        if (it != idNodes.end())
            return (*it).second;
        else
            return nullptr;
    }

    uint32 GameStructure::GenerateID() const
    {
        if (idNodes.empty() == false)
        {
            const uint32 result = (*idNodes.rbegin()).second->GetComponent()->GetID() + 1;
            HKAssertDebug(idNodes.find(result) == idNodes.end());
            return result;
        }
        else
            return 1;
    }

    void GameStructure::OnComponentIDChanged(GameComponent* component, uint32 oldID)
    {
        // Precondition
        HKAssertDebug(component->node &&
                      component->node->structure == this);

        UIntNodeDictionary::iterator itOld = idNodes.find(oldID);
        if (itOld != idNodes.end())
            idNodes.erase(itOld);

        const uint32 id = component->GetID();
        if (id != GameComponent::UnspecifiedID)
            idNodes.insert(UIntNodeDictionary::value_type(id, component->node));
    }

    void GameStructure::OnGameNodeAttached(GameNode* parent, GameNode* child)
    {
        // Precondition
        HKAssertDebug(parent->structure == this);

        struct SetContainerAndRegisterID
        {
            static void Do(GameNode* node, GameStructure* structure)
            {
                // Precondition
                HKAssertDebug(structure->idNodes.find(node->GetComponent()->GetID()) == structure->idNodes.end()); // GameStructure���� �� Method�� ȣ���ϱ� ���� �˻��Ͽ� ���ܸ� �������մϴ�.

                node->structure = structure;

                const uint32 id = node->GetComponent()->GetID();
                if (id != GameComponent::UnspecifiedID)
                    structure->idNodes.insert(UIntNodeDictionary::value_type(id, node));

                typedef GameNode::NodeCollection NodeCollection;
                const NodeCollection& children = node->GetChildren();
                for (NodeCollection::const_iterator it = children.begin(); it != children.end(); it++)
                    Do(*it, structure);
            }
        };

        SetContainerAndRegisterID::Do(child, this);
    }

    void GameStructure::OnGameNodeDetached(GameNode* parent, GameNode* child)
    {
        // Precondition
        HKAssertDebug(parent->structure == this);

        struct ResetContainerAndUnregisterID
        {
            static void Do(GameNode* node, GameStructure* structure)
            {
                node->structure = nullptr;

                const uint32 id = node->GetComponent()->GetID();
                if (id != GameComponent::UnspecifiedID)
                {
                    UIntNodeDictionary::iterator it = structure->idNodes.find(id);
                    HKAssertDebug(it != structure->idNodes.end());
                    structure->idNodes.erase(it);
                }

                typedef GameNode::NodeCollection NodeCollection;
                const NodeCollection& children = node->GetChildren();
                for (NodeCollection::const_iterator it = children.begin(); it != children.end(); it++)
                    Do(*it, structure);
            }
        };

        ResetContainerAndUnregisterID::Do(child, this);
    }
}
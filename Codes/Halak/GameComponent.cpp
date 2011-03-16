#include <Halak/PCH.h>
#include <Halak/GameComponent.h>
#include <Halak/Assert.h>
#include <Halak/Exception.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/ICloneable.h>
#include <Halak/IUpdateable.h>

namespace Halak
{
    const uint GameComponent::UnspecifiedID = 0xFFFFFFFF;

    GameComponent::GameComponent()
        : node(nullptr),
          id(UnspecifiedID),
          alive(true),
          active(true)
    {
    }

    GameComponent::GameComponent(uint id)
        : node(nullptr),
          id(id),
          alive(true),
          active(true)
    {
    }

    GameComponent::~GameComponent()
    {
        if (node)
            node->OnComponentDestructed();
    }

    void GameComponent::SetID(uint value)
    {
        if (id != value)
        {
            // GameStructure���� ���� ID�� GameComponent�� �� �� �̻� ������ �� �����ϴ�.
            if (value != UnspecifiedID && node && node->GetStructure())
                HKIfThrow(node->GetStructure()->Find(value), Exception("value"));

            const uint oldID = id;

            id = value;

            if (node && node->GetStructure())
                node->GetStructure()->OnComponentIDChanged(this, oldID);
        }
    }

    void GameComponent::SetAlive(bool value)
    {
        if (alive != value)
        {
            const Status old = GetStatus();

            alive = value;

            HKAssertDebug(GetStatus() != old); // Alive�� �ٲ�� Status�� �ݵ�� �ٲ�ϴ�.

            OnStatusChanged(old);

            if (node)
                node->OnComponentAliveChanged();
        }
    }
    
    void GameComponent::SetActive(bool value)
    {
        if (active != value)
        {
            const Status old = GetStatus();

            active = value;

            // DeadStatus���� Active�� �ٲ� Status�� �ٲ��� �ʵ�
            // Active�� Status�� ������������ ������ ���� �ʽ��ϴ�.
            if (GetStatus() != old)
                OnStatusChanged(old);
        }
    }

    ICloneable* GameComponent::AcquireCloneableInterface()
    {
        return nullptr;
    }

    const ICloneable* GameComponent::AcquireCloneableInterface() const
    {
        return const_cast<GameComponent*>(this)->AcquireCloneableInterface();
    }

    IUpdateable* GameComponent::AcquireUpdateableInterface()
    {
        return nullptr;
    }

    const IUpdateable* GameComponent::AcquireUpdateableInterface() const
    {
        return const_cast<GameComponent*>(this)->AcquireUpdateableInterface();
    }

    void* GameComponent::AcquireInterface(uint classID)
    {
        switch (classID)
        {
            case ICloneable::ClassID:
                return AcquireCloneableInterface();
            case IUpdateable::ClassID:
                return AcquireUpdateableInterface();
            default:
                return nullptr;
        }
    }

    const void* GameComponent::AcquireInterface(uint classID) const
    {
        return const_cast<GameComponent*>(this)->AcquireInterface(classID);
    }

    void GameComponent::OnStatusChanged(Status /*old*/)
    {
    }
}
#include <Halak/GameComponent.h>
#include <Halak/Assert.h>
#include <Halak/Exception.h>
#include <Halak/GameNode.h>
#include <Halak/GameStructure.h>
#include <Halak/ICloneable.h>
#include <Halak/IUpdateable.h>
#include <Halak/IDrawable.h>

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

    ICloneable* GameComponent::ToCloneableInterface()
    {
        return nullptr;
    }

    const ICloneable* GameComponent::ToCloneableInterface() const
    {
        return nullptr;
    }

    IUpdateable* GameComponent::ToUpdateableInterface()
    {
        return nullptr;
    }

    const IUpdateable* GameComponent::ToUpdateableInterface() const
    {
        return nullptr;
    }

    IDrawable* GameComponent::ToDrawableInterface()
    {
        return nullptr;
    }

    const IDrawable* GameComponent::ToDrawableInterface() const
    {
        return nullptr;
    }

    void* GameComponent::ToInterface(uint classID)
    {
        switch (classID)
        {
            case ICloneable::ClassID:
                return ToCloneableInterface();
            case IUpdateable::ClassID:
                return ToUpdateableInterface();
            case IDrawable::ClassID:
                return ToDrawableInterface();
            default:
                return nullptr;
        }
    }

    const void* GameComponent::ToInterface(uint classID) const
    {
        return const_cast<GameComponent*>(this)->ToInterface(classID);
    }

    void GameComponent::OnStatusChanged(Status /*old*/)
    {
    }
}
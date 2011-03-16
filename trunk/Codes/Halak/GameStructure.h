#pragma once
#ifndef __HALAK_GAMESTRUCTURE_H__
#define __HALAK_GAMESTRUCTURE_H__

#   include <Halak/FWD.h>
#   include <map>

    namespace Halak
    {
        class GameStructure
        {
            HKDeclareClassFOURCC('G', 'S', 'T', 'R');
            HKThisIsNoncopyableClass(GameStructure);
            public:
                GameStructure();
                ~GameStructure();

                GameComponent* Find(uint32 id) const;
                GameNode* FindNode(uint32 id) const;

                inline GameNode* GetRoot() const;

            public:
                uint32 GenerateID() const;

            private:
                void OnComponentIDChanged(GameComponent* component, uint32 old); // call in GameComponent

                // �Ʒ� Attach/Detach�� �ǹ̴� Tree���� Attach/Detach�� �ǹ��մϴ�.
                // �׷��� ���� Container���� GameComponentNode�� �̵�(Deatch=>Attach)������ ȣ���� �ʿ� ����.
                void OnGameNodeAttached(GameNode* parent, GameNode* child); // call in GameComponentNode
                void OnGameNodeDetached(GameNode* parent, GameNode* child); // call in GameComponentNode

            private:
                typedef std::map<uint32, GameNode*> UIntNodeDictionary;

            private:
                GameNode* root;
                UIntNodeDictionary idNodes;

                friend class GameComponent;
                friend class GameNode;
        };
    }

#   include <Halak/GameStructure.inl>

#endif
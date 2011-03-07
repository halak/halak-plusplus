#pragma once
#ifndef __HALAK_GAMENODE_H__
#define __HALAK_GAMENODE_H__

#   include <Halak/FWD.h>
#   include <vector>

    namespace Halak
    {
        class GameNode
        {
            public:
                typedef std::vector<GameNode*> NodeCollection;

            public:
                GameNode(GameComponent* component);
                ~GameNode();

                GameNode* AttachChild(GameComponent* item);
                void AttachChild(GameNode* item);
                bool DetachChild(GameNode* item);
                void DetachAllChildren();

                GameComponent* FindChild(uint id, bool searchAllChildren) const;
                GameNode* FindChildNode(uint id, bool searchAllChildren) const;
                GameNode* FindChildNode(GameComponent* item, bool searchAllChildren) const;

                inline GameComponent* GetComponent() const;
                inline GameNode* GetParnet() const;
                inline const NodeCollection& GetChildren() const;
                inline GameStructure* GetStructure() const;

                inline bool IsRoot() const;

            private:
                struct NullComponentTag {};
                GameNode(NullComponentTag);

                void OnComponentDestructed();
                void OnComponentAliveChanged();

            private:
                GameComponent* component;
                GameNode* parent;
                NodeCollection children;
                GameStructure* structure;

            private:
                GameNode(const GameNode&);
                GameNode& operator = (const GameNode&);

                friend class GameComponent;
                friend class GameStructure;
        };
    }

#   include <Halak/GameNode.inl>

#endif
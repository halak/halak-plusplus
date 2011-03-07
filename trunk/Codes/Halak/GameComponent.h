#pragma once
#ifndef __HALAK_GAMECOMPONENT_H__
#define __HALAK_GAMECOMPONENT_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
#       define HKDeclareGameComponentClass(id)
#       define HKDeclareGameComponentClassFOURCC(a, b, c, d)

        /// Game이란 Application을 구성하는 요소의 기반 class.
        class GameComponent
        {
            public:
                enum Status
                {
                    DeadStatus,
                    AliveStatus,
                    ActiveStatus
                };

            public:
                static const uint UnspecifiedID;

            public:
                virtual ~GameComponent();

                inline uint GetID() const;
                       void SetID(uint value);

                inline Status GetStatus() const;

                inline bool GetAlive() const;
                       void SetAlive(bool value);

                inline bool GetActive() const;
                       void SetActive(bool value);

                virtual       ICloneable*  ToCloneableInterface();
                virtual const ICloneable*  ToCloneableInterface() const;
                virtual       IUpdateable* ToUpdateableInterface();
                virtual const IUpdateable* ToUpdateableInterface() const;
                virtual       IDrawable*   ToDrawableInterface();
                virtual const IDrawable*   ToDrawableInterface() const;

            protected:
                GameComponent();
                explicit GameComponent(uint id);

                virtual void OnStatusChanged(Status old);

            private:
                GameNode* node;
                uint id;
                bool alive;
                bool active;

            private:
                GameComponent(const GameComponent&);
                GameComponent& operator = (const GameComponent&);

                friend class GameNode;
                friend class GameStructure;
        };
    }

#   include <Halak/GameComponent.inl>

#endif
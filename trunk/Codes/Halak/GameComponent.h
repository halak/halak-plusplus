#pragma once
#ifndef __HALAK_GAMECOMPONENT_H__
#define __HALAK_GAMECOMPONENT_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        /// Game이란 Application을 구성하는 요소의 기반 class.
        class GameComponent
        {
            HKClassFOURCC('G', 'A', 'C', 'P')
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

                inline uint32 GetID() const;
                       void SetID(uint32 value);

                inline Status GetStatus() const;

                inline bool GetAlive() const;
                       void SetAlive(bool value);

                inline bool GetActive() const;
                       void SetActive(bool value);

                virtual       ICloneable*  QueryCloneableInterface();
                virtual const ICloneable*  QueryCloneableInterface() const;
                virtual       IUpdateable* QueryUpdateableInterface();
                virtual const IUpdateable* QueryUpdateableInterface() const;
                virtual       void* QueryInterface(uint classID);
                virtual const void* QueryInterface(uint classID) const;

            protected:
                GameComponent();
                GameComponent(uint32 id);

                virtual void OnStatusChanged(Status old);

            private:
                GameNode* node;
                uint32 id;
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
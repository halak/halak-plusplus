#pragma once
#ifndef __HALAK_GAMECOMPONENT_H__
#define __HALAK_GAMECOMPONENT_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
#       define HKDeclareGameComponentClass(id)  public: \
                                                    static const uint32 ClassID = id; \
                                                    virtual uint32 GetClassID() const { return ClassID; } \
                                                private:
#       define HKDeclareGameComponentClassFOURCC(a, b, c, d) HKDeclareGameComponentClass(HKMakeFOURCC(a, b, c, d))

        /// Game�̶� Application�� �����ϴ� ����� ��� class.
        class GameComponent
        {
            HKDeclareGameComponentClassFOURCC('G', 'A', 'C', 'P')
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

                virtual       ICloneable*  AcquireCloneableInterface();
                virtual const ICloneable*  AcquireCloneableInterface() const;
                virtual       IUpdateable* AcquireUpdateableInterface();
                virtual const IUpdateable* AcquireUpdateableInterface() const;
                virtual       void* AcquireInterface(uint classID);
                virtual const void* AcquireInterface(uint classID) const;

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
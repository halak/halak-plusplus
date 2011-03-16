#pragma once
#ifndef __HALAK_TIMELINE_H__
#define __HALAK_TIMELINE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <vector>

    namespace Halak
    {
        class Timeline : public GameComponent, public IUpdateable
        {
            HKDeclareGameComponentClassFOURCC('T', 'M', 'L', 'N');
            public:
                struct Item
                {
                    IUpdateable*   RawPointer;
                    IUpdateablePtr SharedPointer;

                    inline Item();
                    inline Item(IUpdateable* item);
                    inline Item(IUpdateablePtr item);

                    inline bool operator == (const Item& right) const;
                    inline bool operator != (const Item& right) const;
                };

            public:
                typedef std::vector<Item> ItemCollection;
                typedef std::vector<IUpdateable*> UpdateableCollection;

            public:
                Timeline();
                explicit Timeline(uint id);
                virtual ~Timeline();

                virtual void Update(float dt, uint timestamp);

                void Add(IUpdateable* item);
                void Add(IUpdateablePtr item);
                bool Remove(IUpdateable* item);
                bool Remove(IUpdateablePtr item);
                void RemoveAt(int index);
                void Clear();

                const ItemCollection& GetItems() const;

                float GetSpeed() const;
                void  SetSpeed(float value);

                virtual IUpdateable* AcquireUpdateableInterface();

            private:
                ItemCollection items;
                UpdateableCollection temporaryItems;
                float speed;
                uint lastTimestamp;
        };
    }

#   include <Halak/Timeline.inl>

#endif
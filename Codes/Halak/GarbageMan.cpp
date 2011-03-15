#include <Halak/GarbageMan.h>
#include <Halak/IDisposable.h>
#include <algorithm>

namespace Halak
{
    GarbageMan::GarbageMan()
    {
    }

    GarbageMan::GarbageMan(uint id)
        : GameComponent(id)
    {
    }

    GarbageMan::~GarbageMan()
    {
        DisposeAll();
    }
    
    void GarbageMan::DisposeAll()
    {
        for (DisposableCollection::const_iterator it = items.begin(); it != items.end();)
        {
            if (IDisposablePtr item = (*it).Lock())
            {
                item->Dispose();
                it++;
            }
            else
                items.erase(it++);
        }
    }

    void GarbageMan::Add(IDisposableWeakPtr item)
    {
        if (item.IsAlive() == false)
            return;

        items.push_back(item);
    }

    bool GarbageMan::Remove(IDisposableWeakPtr item)
    {
        if (item.IsAlive() == false)
            return false;

        IDisposablePtr lockedItem = item.Lock();
        for (DisposableCollection::const_iterator it = items.begin(); it != items.end();)
        {
            if ((*it).IsAlive() == false)
            {
                items.erase(it++);
                continue;
            }

            if ((*it).Lock() == lockedItem)
            {
                items.erase(it);
                return true;
            }
            else
                it++;
        }

        return false;
    }
    
    void GarbageMan::Clear()
    {
        items.clear();
    }

    bool GarbageMan::Contains(IDisposableWeakPtr item) const
    {
        if (item.IsAlive() == false)
            return false;

        IDisposablePtr lockedItem = item.Lock();

        for (DisposableCollection::const_iterator it = items.begin(); it != items.end(); it++)
        {
            if ((*it).IsAlive() && (*it).Lock() == lockedItem)
                return true;
        }

        return false;
    }

    const GarbageMan::DisposableCollection& GarbageMan::GetItems() const
    {
        return items;
    }
}

#include <Halak/GarbageMan.h>
#include <Halak/IDisposable.h>
#include <algorithm>

namespace Halak
{
    GarbageMan::GarbageMan()
    {
    }

    GarbageMan::~GarbageMan()
    {
        DisposeAll();
    }
    
    void GarbageMan::DisposeAll()
    {
        for (DisposableCollection::const_iterator it = entries.begin(); it != entries.end();)
        {
            if (IDisposablePtr item = (*it).lock())
            {
                item->Dispose();
                it++;
            }
            else
                entries.erase(it++);
        }
    }

    void GarbageMan::Add(IDisposableWeakPtr item)
    {
        if (item.expired())
            return;

        entries.push_back(item);
    }

    bool GarbageMan::Remove(IDisposableWeakPtr item)
    {
        if (item.expired())
            return false;

        IDisposablePtr lockedItem = item.lock();
        for (DisposableCollection::const_iterator it = entries.begin(); it != entries.end();)
        {
            if ((*it).expired())
            {
                entries.erase(it++);
                continue;
            }

            if ((*it).lock() == lockedItem)
            {
                entries.erase(it);
                return true;
            }
            else
                it++;
        }

        return false;
    }
    
    void GarbageMan::Clear()
    {
        entries.clear();
    }

    bool GarbageMan::Contains(IDisposableWeakPtr item) const
    {
        if (item.expired())
            return false;

        IDisposablePtr lockedItem = item.lock();

        for (DisposableCollection::const_iterator it = entries.begin(); it != entries.end(); it++)
        {
            if ((*it).expired() == false && (*it).lock() == lockedItem)
                return true;
        }

        return false;
    }

    const GarbageMan::DisposableCollection& GarbageMan::GetEntries() const
    {
        return entries;
    }
}

#include <Halak/PCH.h>
#include <Halak/GameComponentFactory.h>
#include <Halak/Assert.h>
#include <Halak/GameComponent.h>
#include <algorithm>
#include <vector>

namespace Halak
{
    struct Entry
    {
        uint32 ID;
        GameComponentFactory::CreateFunction Function;

        Entry(uint32 id, GameComponentFactory::CreateFunction function)
            : ID(id),
              Function(function)
        {
        }
    };

    static std::vector<Entry> Entries;

    void GameComponentFactory::AddEntry(uint32 id, CreateFunction function)
    {
        Entries.push_back(Entry(id, function));
    }

    void GameComponentFactory::SortEntries()
    {
        struct Compare
        {
            bool operator () (const Entry& a, const Entry& b)
            {
                return a.ID < b.ID;
            }
        };

        std::sort(Entries.begin(), Entries.end(), Compare());
    }

    GameComponent* GameComponentFactory::Create(uint32 id)
    {
        HKAssertDebug(Entries.empty() == false);

        int lower = 0;
        int upper = static_cast<int>(Entries.size());

        while (upper - lower > 0)
        {
            const int index = lower + static_cast<int>((upper - lower) / 2);

            if (id < Entries[index].ID)
                upper = index + 1;
            else if (id > Entries[index].ID)
                lower = index;
            else
                return (*Entries[index].Function)();
        }

        return nullptr;
    }
}
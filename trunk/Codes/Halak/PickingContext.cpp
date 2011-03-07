#include <Halak/PickingContext.h>
#include <Halak/Assert.h>

namespace Halak
{
    PickingContext::PickingContext(const Ray& ray, bool ordered, bool findAll, bool debug)
        : ray(ray),
          options(MakeOptions(ordered, findAll, debug))
    {
    }

    PickingContext::PickingContext(const PickingContext& original)
        : ray(original.ray),
          options(original.options),
          results(original.results)
    {
    }

    bool PickingContext::Push(const PickResult& result)
    {
        if (IsFindAll())
        {
            if (IsOrdered())
            {
                for (ResultCollection::iterator it = results.begin(); it != results.end(); it++)
                {
                    if ((*it).Distance > result.Distance)
                    {
                        results.insert(it, result);
                        return true;
                    }
                }
                
                results.push_back(result);
                return true;
            }
            else
            {
                results.push_back(result);
                return true;
            }
        }
        else
        {
            if (IsOrdered())
            {
                if (results.empty())
                    results.push_back(result);
                else
                {
                    if (results.front().Distance > result.Distance)
                        results.front() = result;
                }

                return true;
            }
            else
            {
                HKAssert(results.empty());
                results.push_back(result);
                return false;
            }
        }
    }

    PickingContext& PickingContext::operator = (const PickingContext& right)
    {
        ray = right.ray;
        options = right.options;
        results = right.results;
        return *this;
    }

    bool PickingContext::operator == (const PickingContext& right) const
    {
        return (ray == right.ray &&
                options == right.options &&
                results == right.results);
    }

    bool PickingContext::operator != (const PickingContext& right) const
    {
        return !operator == (right);
    }

    dword PickingContext::MakeOptions(bool ordered, bool findAll, bool debug)
    {
        dword result = 0x00000000;
        if (ordered)
            result |= OrderedFlag;
        if (findAll)
            result |= FindAllFlag;
        if (debug)
            result |= DebugFlag;
        return result;
    }
}
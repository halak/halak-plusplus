#include <Halak/SubTimeline.h>

namespace Halak
{
    SubTimeline::~SubTimeline()
    {
    }

    void SubTimeline::SetParent(Timeline* value)
    {
        if (parent != value)
        {
            Timeline* oldParent = parent;

            if (oldParent)
                oldParent->Remove(this);

            parent = value;

            if (parent)
                parent->Add(this);
        }
    }
}
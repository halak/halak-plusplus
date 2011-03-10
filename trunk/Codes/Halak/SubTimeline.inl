namespace Halak
{
    SubTimeline::SubTimeline()
        : parent(nullptr)
    {
    }

    SubTimeline::SubTimeline(uint id)
        : Timeline(id),
          parent(nullptr)
    {
    }

    Timeline* SubTimeline::GetParent() const
    {
        return parent;
    }
}
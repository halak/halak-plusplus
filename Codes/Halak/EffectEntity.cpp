#include <Halak/EffectEntity.h>
#include <Halak/ISpatial.h>

namespace Halak
{
    EffectEntity::EffectEntity()
        : Entity()
    {
    }

    EffectEntity::EffectEntity(const String& name)
        : Entity(name)
    {
    }

    EffectEntity::EffectEntity(const EffectEntity& original, CloningContext& context)
        : Entity(original, context)
    {
    }

    EffectEntity::~EffectEntity()
    {
    }

    void EffectEntity::Dispose()
    {
        Entity::Dispose();
        DynamicDispose(origin);
        origin.Reset();
    }

    ISpatialPtr EffectEntity::GetOrigin() const
    {
        return origin;
    }

    void EffectEntity::SetOrigin(ISpatialPtr value)
    {
        if (origin != value)
        {
            ISpatialPtr old;
            old.Swap(origin);

            origin = value;

            OnOriginChanged(old);
        }
    }

    void EffectEntity::OnOriginChanged(ISpatialPtr /*old*/)
    {
    }
}
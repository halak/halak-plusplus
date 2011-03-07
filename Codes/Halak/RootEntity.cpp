#include <Halak/RootEntity.h>

namespace Halak
{
    RootEntity::RootEntity()
        : Entity()
    {
    }

    RootEntity::RootEntity(const String& name)
        : Entity(name)
    {
    }

    RootEntity::RootEntity(const RootEntity& original, CloningContext& context)
        : Entity(original, context),
          author(original.author),
          comment(original.comment)
    {
    }

    RootEntity::~RootEntity()
    {
    }

    RootEntity* RootEntity::Clone() const
    {
        return static_cast<RootEntity*>(ICloneable::Clone());
    }

    RootEntity* RootEntity::CloneWith(CloningContext& context) const
    {
        return new RootEntity(*this, context);
    }

    const String& RootEntity::GetAuthor() const
    {
        return author;
    }

    void RootEntity::SetAuthor(const String& value)
    {
        author = value;
    }

    const String& RootEntity::GetComment() const
    {
        return comment;
    }

    void RootEntity::SetComment(const String& value)
    {
        comment = value;
    }
}
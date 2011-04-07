#include <Halak/PCH.h>
#include <Halak/GameModule.h>

namespace Halak
{
    GameModule::GameModule()
    {
    }

    GameModule::GameModule(uint32 id)
        : GameComponent(id)
    {
    }

    GameModule::GameModule(const GameModule& original, CloningContext& context)
        : GameComponent(),
          ICloneable(context),
          name(original.name),
          filename(original.filename),
          description(original.description)
    {
    }

    GameModule::~GameModule()
    {
    }

    GameModule* GameModule::CloneWith(CloningContext& context) const
    {
        return new GameModule(*this, context);
    }

    ICloneable* GameModule::AcquireCloneableInterface()
    {
        return this;
    }
}
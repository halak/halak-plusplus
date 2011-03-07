#include <Halak/Startup.h>
#include <Halak/All.h>

namespace Halak
{
    void __Startup__()
    {
        CommandHistory::__Startup__();
        CommandQueue::__Startup__();
        Command::__Startup__();
            RestorableCommand::__Startup__();
                BatchCommand::__Startup__();
                ChangePropertyCommand::__Startup__();

        Entity::__Startup__();
            RootEntity::__Startup__();
            EffectEntity::__Startup__();
                ParticleEffectEntity::__Startup__();

        SimpleParticleEmitter::__Startup__();
    }

    void Startup()
    {
        __Startup__();
    }
}